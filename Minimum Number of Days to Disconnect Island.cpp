class Solution {
public:

    static constexpr int nm = 32;
    static constexpr pair<int, int> dirs[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int m, n;
    int num[nm][nm], low[nm][nm], cnt;
    bool hasAp;

    void dfs(int i, int j, int pi, int pj, vector<vector<int>> &grid) {
        num[i][j] = low[i][j] = ++cnt;
        int nChild = 0;
        for (auto [dx, dy]: dirs) {
            int i2 = i + dx, j2 = j + dy;
            if (i2 == pi && j2 == pj) continue;
            if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && grid[i2][j2]) {
                if (!num[i2][j2]) {
                    nChild++;
                    dfs(i2, j2, i, j, grid);
                    low[i][j] = min(low[i][j], low[i2][j2]);
                    if (pi != -1 && low[i2][j2] >= num[i][j]) {
                        hasAp = 1;
                    }
                } else {
                    low[i][j] = min(low[i][j], num[i2][j2]);
                }
            }
        }
        if (pi == -1 && nChild >= 2) hasAp = 1;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int components = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !num[i][j]) {
                    components++;
                    if (components > 1) {
                        return 0;
                    }
                    dfs(i, j, -1, -1, grid);
                }
            }
        }

        if (components != 1) return 0;
        if (hasAp) return 1;
        if (cnt == 1) return 1;
        return 2;
    }
};
