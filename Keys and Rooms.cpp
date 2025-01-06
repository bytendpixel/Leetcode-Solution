class Solution {
public:
    int vis[10000]={false};

    void dfs(vector<vector<int>>& adj, int x){
        vis[x]=1;

        for(auto y:adj[x]){
            if(!vis[y])
                dfs(adj,y);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        dfs(adj,0);
        for(int i=1;i<n;i++ ){
            if(!vis[i])return false;
        }
        return 1;
    }
};
