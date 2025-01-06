class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001] = {0}; // Static array for speed
        for (char c1 : text1) {
            int prev = 0;
            for (int j = 1; j <= text2.size(); ++j) {
                int temp = dp[j];
                dp[j] = (c1 == text2[j - 1]) ? prev + 1 : max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[text2.size()];
    }
};
