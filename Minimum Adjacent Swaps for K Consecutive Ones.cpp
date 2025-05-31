class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        int pos[n];
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) pos[sz++] = i;
        }
        for (int i = 0; i < sz; i++) {
            pos[i] -= i;
        }
        int ki = 0, ka = 0;
        for (int i = 0; i < k / 2; i++) ki += pos[i];
        for (int i = k - 1; i >= k - (k / 2); i--) ka += pos[i];
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < sz; i++) {
            ans = min(ans, ka - ki);
            if (i + k < sz) {
                ki -= pos[i];
                ki += pos[i + k / 2];
                ka -= pos[i + k - (k / 2)];
                ka += pos[i + k];
            }
        }
        return ans;
    }
};
