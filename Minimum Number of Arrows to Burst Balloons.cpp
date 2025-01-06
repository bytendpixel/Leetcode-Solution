class Solution {
public:
    inline int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> P(points.size()); // moving into pais improves locality
        for(int i = 0; i <points.size(); ++i){
            P[i].first = points[i][0];
            P[i].second = points[i][1];

        }
        sort(P.begin(), P.end(), [](auto x, auto y){ return x.second< y.second;});
        int count = 0;
        int i = 0, j = 0;
        for(; i < P.size(); ){
            j = i + 1;
            while(j < P.size() && P[j].first <= P[i].second)  ++j;
            i = j;
            ++count;
        }
        return count;
    }
};
