class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int c=0;
        for (int i=0;i<nums.size()-1;i++)
        {
            for (int j=i+1;j<nums.size();j++)
            {
                c++;
                if (nums[i]==nums[j] && abs(i-j)<=k)
                return true;
                if (c==40)
                break;
            }
            c=0;
        }
        return false;
    }
};
