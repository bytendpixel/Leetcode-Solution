class Solution {
public:
    constexpr size_t next(const vector<int>& nums, size_t i) {
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            ++i;
        }
        return i;
    }

    // Complexity
    // Time: O(n log n + m log m)
    // Space: O(1)
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        auto answer = vector<vector<int>>(2);
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        size_t i = 0, j = 0;
        const size_t sz1 = nums1.size(), sz2 = nums2.size();

        while (i < sz1 && j < sz2) {
            if (nums1[i] < nums2[j]) {
                // Element from num1 is not present in num2
                answer[0].push_back(nums1[i]);
                i = next(nums1, i);
            } else if (nums1[i] > nums2[j]) {
                // Element from num2 is not present in num1
                answer[1].push_back(nums2[j]);
                j = next(nums2, j);
            } else {
                // Skip elements that exist in both arrays
                i = next(nums1, i);
                j = next(nums2, j);
            }
        }

        while (i < sz1) {
            answer[0].push_back(nums1[i]);
            i = next(nums1, i);
        }

        while (j < sz2) {
            answer[1].push_back(nums2[j]);
            j = next(nums2, j);
        }

        return answer;
    }
};
