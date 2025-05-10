class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        time[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [t, node] = pq.top();
            auto [i, j] = node;
            pq.pop();
            if(i == n-1 && j == n-1){
                break;
            }
            for(int k = 0; k < 4; k++){
                int x = i+dx[k], y = j+dx[k+1];
                if(x < 0 || x >= n || y < 0 || y >= n){
                    continue;
                }
                int newTime = max(grid[x][y], t);
                if(newTime < time[x][y]){
                    time[x][y] = newTime;
                    pq.push({newTime, {x, y}});
                }
            }
        }

        return time[n-1][n-1];
    }
};
