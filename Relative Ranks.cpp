class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int> score_copy=score;
        vector<pair<int,int>> mpp;
        for(int i=0;i<n;i++)
        {
            mpp.emplace_back(score[i],i);
        }
        sort(mpp.begin(),mpp.end());
        reverse(mpp.begin(),mpp.end());
        vector<string> ans(n);
        string arr[3]={"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(int i=0;i<n;i++)
        {
            int j=mpp[i].second;
            if(i<3)
            {
                ans[j]=arr[i];
            }
            else
            ans[j]=to_string(i+1);
        }
        return ans;
    }
};
