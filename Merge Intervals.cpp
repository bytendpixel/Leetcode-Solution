class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the first elements in the intervals
        sort(intervals.begin(),intervals.end(),[](const vector<int>& i1, const vector<int>& i2){ return i1[0]<i2[0];});
        vector<vector<int>> res;
        //check if there is overlapping
        int right=intervals[0][1];
        int left=intervals[0][0];
        for(int i=1;i<intervals.size();i++){
            if(right>=intervals[i][0]){
                right=max(right,intervals[i][1]);
            } else {
                res.push_back(vector<int>({left,right}));
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        //last one easy to miss
        res.push_back(vector<int>({left,right}));
        return res;
        
    }
};
