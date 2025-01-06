class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int hottest=0;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int currtemp = temperatures[i];
            if(currtemp>=hottest)
            {
                hottest=currtemp;
                continue;
            }
            int days = 1;
            while(temperatures[i+days]<=currtemp)
            {
                days+=ans[i+days];
            }
            ans[i]=days;
        }
        return ans;
    }
};
