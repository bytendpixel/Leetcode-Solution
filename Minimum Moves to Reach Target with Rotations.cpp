constexpr int impossible = 100000; 
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        const size_t n = grid.size();
        // use a large number to specify that this movement is impossible
        // 0 is horizontal, 1 is vertical
        vector<vector<int>> dp(2, vector(n + 1, impossible));  
        // our starting point
        dp[0][1] = -1; 
        for(size_t i = 0; i < n; i++) {
            for(size_t j =0; j < n; j++) {
                int dp1 = dp[1][j + 1];
                // handle horizontal
                if(grid[i][j] == 1 || j + 1 == n || grid[i][j + 1] == 1) {
                    dp[0][j + 1] = impossible;
                } else {
                    dp[0][j + 1] = min(dp[0][j + 1] + 1, dp[0][j] + 1);
                    // check rotation from this position
                    if(i + 1 < n && grid[i + 1][j] == 0 && grid[i + 1][j + 1] == 0) {
                        dp1 = min(dp[0][j + 1], dp1);
                    }
                }
                // handle vertical
                if(grid[i][j] == 1 || i + 1 == n || grid[i + 1][j] == 1) {
                    dp[1][j + 1] = impossible;
                } else {
                    dp[1][j + 1] = min(dp[1][j] + 1, 1 + dp1);
                    // check rotation from this position
                    if(j + 1 < n && grid[i][j + 1] == 0 && grid[i + 1][j + 1] == 0) {
                        dp[0][j + 1] = min(dp[0][j + 1], 1 + dp[1][j + 1]);  
                    }
                }
            }
        }
        if(dp[0][n-1] >= impossible) {
            return -1;
        }
        return dp[0][n-1];
    }
};
