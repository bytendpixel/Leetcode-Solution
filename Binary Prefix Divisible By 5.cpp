class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<bool> answer(n); 

        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = (ans[i - 1] * 2 + nums[i]) % 5; // build prefix modulo 5
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] % 5 == 0) {
                answer[i] = true;
            } else {
                answer[i] = false;
            }
        }

        return answer;
    }
};
