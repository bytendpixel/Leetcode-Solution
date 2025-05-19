class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // 如果 k 足夠大，最短路就是曼哈頓距離
        if (k >= m + n - 2) return m + n - 2;
        
        // seen[r][c][rem] = 是否走過 (r,c) 且剩 rem 次消障
        vector<vector<vector<bool>>> seen(
            m, vector<vector<bool>>(n, vector<bool>(k+1, false))
        );
        queue<tuple<int,int,int,int>> q; 
        // (row, col, steps so far, remaining eliminations)
        q.push({0, 0, 0, k});
        seen[0][0][k] = true;
        
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!q.empty()) {
            auto [r, c, steps, rem] = q.front();
            q.pop();
            // 到達終點，返回步數
            if (r == m-1 && c == n-1) 
                return steps;
            
            // 四方向探索
            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) 
                    continue;

                //判斷是0還是1, obstacle要判斷要不要消掉
                int nrem = 0;               
                if(grid[nr][nc] == 1) {
                    nrem = rem -1;
                }
                else {
                    nrem = rem;
                }
            
                // 若是空地(grid=0) nrem=rem；若是障礙(grid=1) nrem=rem-1
                if (nrem >= 0 && !seen[nr][nc][nrem]) {
                    seen[nr][nc][nrem] = true;
                    q.push({nr, nc, steps + 1, nrem});
                }
            }
        }
        
        return -1;  // BFS 結束仍未到終點
    }
};
