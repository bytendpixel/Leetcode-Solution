class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int total = 0, lowest = INT_MAX, highest = INT_MIN, bestIncrease = 0;
        for (int i = 1; i < nums.size(); i++) {
            int diff = abs(nums[i] - nums[i - 1]);
            total += diff;
            lowest = min(lowest, max(nums[i], nums[i - 1]));
            highest = max(highest, min(nums[i], nums[i - 1]));
            bestIncrease = max(bestIncrease, abs(nums[0] - nums[i]) - diff);
            bestIncrease = max(bestIncrease, abs(nums[nums.size() - 1] - nums[i - 1]) - diff);
        }
        return total + max(bestIncrease, 2 * (highest - lowest));
    }
};
