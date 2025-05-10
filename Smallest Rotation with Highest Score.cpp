class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> rotations(n+2, 0);

        for(int i = 0; i < n; i++) {
            int minr, maxr;
            if(nums[i] <= i) {
                minr = 0;
                maxr = i - nums[i];
                rotations[minr]++;
                rotations[maxr + 1]--;
                // second interval
                rotations[i + 1]++;
                rotations[n + 1]--;
            } else {
                minr = i + 1;
                maxr = n - nums[i] + i;
                rotations[minr]++;
                rotations[maxr + 1]--;
            }
        }

        int bestr = n, best_score = 0, cnt = 0;
        for(int i = 0; i <= n + 1; i++) {
            cnt += rotations[i];
            // cout << rotations[i] << " ";
            if(cnt > best_score) {
                best_score = cnt;
                bestr = i;
            }
        }
        return bestr;
    }
};
