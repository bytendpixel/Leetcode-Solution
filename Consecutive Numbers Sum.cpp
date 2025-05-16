class Solution {
public:
    int consecutiveNumbersSum(int N) {

        int count = 0;
        int upper_limit = (int)(sqrt(2 * N + 0.25) - 0.5);

        for (int k = 1; k <= upper_limit; ++k) {
            if ((N - k * (k + 1) / 2) % k == 0)
                count++;
        }
        return count;
        
    }
};
