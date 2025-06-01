class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dist=abs(rCenter-i)+abs(cCenter-j);
                v.push_back({dist,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)ans.push_back({v[i].second.first,v[i].second.second});
        return ans;
    }
};
