class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int counter = 0;
        int sum = 0;
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum < k) {
                left += 1;
            } else if (sum > k) {
                right -= 1;
            } else {
                counter += 1;
                left += 1;
                right -= 1;
            }
        }
        return counter;
    }
};
