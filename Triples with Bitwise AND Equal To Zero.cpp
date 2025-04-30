const int mx = (1<<16);
const int mb = 16;
int f[mx];

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        //memset(f, 0, sizeof(f));
        fill(begin(f), end(f), 0);
        //vector<int> f(mx);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) f[nums[i] & nums[j]]++;
        for(int i = 0; i < mb; ++i)
            for(int m = 0; m < mx; ++m)
                if((1<<i) & m) f[m] += f[m ^ (1<<i)];
        int ans = 0;
        for(auto num : nums) ans += f[(mx-1) & (~num)];
        return ans;
    }
};
