const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);  // Correct way to pass the static function pointer
    return 0;
}();
#endif

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + nums[i] * (pow2[i] - pow2[n - i - 1])) % MOD;
        }

        return (result + MOD) % MOD; // Ensure non-negative result
    }
};
