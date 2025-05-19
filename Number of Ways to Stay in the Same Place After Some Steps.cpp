class Solution 
{
public:
    const int MOD = 1e9 + 7;

    int numWays(int steps, int arrLen) 
    {
        arrLen = min(arrLen, steps / 2 + 1); // optimization to limit the array size

        vector<int> prev(arrLen + 2, 0), curr(arrLen + 2, 0);

        prev[1] = 1;  // dp[0][1] = 1 → at position 0 (shifted by +1) with 0 steps

        for (int step = 1; step <= steps; step++) 
        {
            for (int index = 1; index <= arrLen; index++) 
            {
                if ((index - 1) > step) 
                {
                    curr[index] = 0;
                } 
                else 
                {
                    curr[index] = ((prev[index - 1] + prev[index + 1]) % MOD + prev[index]) % MOD;
                }
            }

            prev = curr; // move to next step
        }

        return prev[1];  // maps to actual index 0
    }
};
