class Solution {
public:
    int findLHS(vector<int>& nums) {
     sort(nums.begin(), nums.end());
     int left = 0, ans = 0;
      for ( int right = 0, n = nums.size(); right < n; ++right){
        while ( nums[right] - nums[left] > 1) ++left;
        if ( nums[right] - nums[left] == 1) ans = max(ans, right - left + 1);
      }
        return ans;
         
    }
};
