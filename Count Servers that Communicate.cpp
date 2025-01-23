class DSU{
    vector<int> parent;
    vector<int> size;
    public:
        DSU(int cap){
            parent.resize(cap, 0);
            size.resize(cap, 1);
            for(int i=0;i<cap;i++){
                parent[i] = i;
            }
        }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int a , int b){
        a = findParent(a);
        b = findParent(b);
        if(a==b) return false;
        if(size[b]>size[a]) swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
        return true;
    }
    int sizeEqualToTwo(){
        int cnt = 0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i and size[i]==2){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowHash(n);
        vector<int> colHash(m);
        DSU dsu(n+m);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                    dsu.unionBySize(i, n+j);
                }
            }
        }
        cout << dsu.sizeEqualToTwo() << "\n";
        ans-=dsu.sizeEqualToTwo();
        return ans;
    }
};
