class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];
        int lastl = min(grid[0][0], grid[0][1]);
        int seclastl = max(grid[0][0], grid[0][1]);
        int lastj = 0;
        if (grid[0][0] > grid[0][1]) {
            lastj = 1;
        }

        for (int i = 2; i < n; i++) {
            if (grid[0][i] <= lastl) {
                seclastl = lastl;
                lastl = grid[0][i];
                lastj = i;
            } else if (grid[0][i] < seclastl) {
                seclastl = grid[0][i];
            }
        }

        for (int i = 1; i < n; i++) {

            int curm; 
            int securm;
            int curlj = 0;
            if (lastj) {
                curm = grid[i][0] + lastl;
            } else {
                curm = grid[i][0] + seclastl;
            }
            if (lastj != 1) {
                securm = grid[i][1] + lastl;
            } else {
                securm = grid[i][1] + seclastl;
            }
            if (securm < curm) {
                swap(securm, curm);
                curlj = 1;
            }

            for (int j = 2; j < lastj; j++) {
                int v = grid[i][j] + lastl;
                if (v <= curm) {
                    securm = curm;
                    curm = v;
                    curlj = j;
                } else if (v < securm) {
                    securm = v;
                }
            }

            if ((lastj > 1) && grid[i][lastj] + seclastl <= curm) {
                securm = curm;
                curm = grid[i][lastj] + seclastl;
                curlj = lastj;
            } else if (grid[i][lastj] + seclastl < securm) {
                securm = grid[i][lastj] + seclastl;
            }

            for (int j = lastj + 1; j < n; j++) {
                int v = grid[i][j] + lastl;
                if (v <= curm) {
                    securm = curm;
                    curm = v;
                    curlj = j;
                } else if (v < securm) {
                    securm = v;
                }
            }

            lastl = curm;
            seclastl = securm;
            lastj = curlj;
        }

        return lastl;
    }
};
