class Solution {
public:
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {

        vector<int>p(n+1);
        
        for(int i=1;i<n+1;i++)
            p[i] = i;

        for(int i = t+1;2*i<=n;++i) {
            for(int j=i<<1;j<=n;j+=i){
                p[findPar(j,p)] = findPar(i,p); 
            }
        }

        for(int i=1;i<=n;i++)
            p[i] = findPar(i,p);

        vector<bool>ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = p[queries[i][0]] == p[queries[i][1]];
        }
        return ans;
    }

    int findPar(int a, vector<int>&p) {
        if(p[a]!=a)
            return p[a] = findPar(p[a], p);
        return a;
    }
};
