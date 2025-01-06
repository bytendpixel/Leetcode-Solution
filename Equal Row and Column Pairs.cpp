class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> tp = grid;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(tp[i][j], tp[j][i]);
        int ans = 0;
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
            mp[grid[i]]++;
        for (int j = 0; j < n; j++)
            ans += mp[tp[j]];
        return ans;
    }
};
