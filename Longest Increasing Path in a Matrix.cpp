class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int f(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        for(int k=0;k<4;k++) {
            int ni = i+dr[k], nj = j+dc[k];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&mat[ni][nj]>mat[i][j]) {
                ans = max(ans, 1+f(ni, nj, n, m, mat, dp));
            }
        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans, f(i, j, n, m, matrix, dp));
            }
        }
        return ans;
    }
};
