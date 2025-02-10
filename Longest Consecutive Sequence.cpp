int a[2000000001];
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 1;
        int* a = new int[2000000002];
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            nums[i] += 1000000000;
            if (a[nums[i]]) {
                swap(nums[i], nums[s - 1]);
                s--;
                i--;
                continue;
            }
            a[nums[i]] = 1;
        }

        for (int i = 0; i < s; i++) {
            int x = nums[i] + 1;
            while (a[x] == 1) {
                a[x] = -1;
                a[nums[i]]++;
                result = max(result, a[nums[i]]);
                x++;
            }
            if (a[x] > 1) {
                a[nums[i]] += a[x];
                result = max(result, a[nums[i]]);
            }
        }
        delete[] a;
        return result;
    }
};
