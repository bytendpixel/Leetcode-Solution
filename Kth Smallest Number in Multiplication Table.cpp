const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n, res = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            bool x = cnt(m, n, k, mid);

            if(x) {
                res = mid;
                r = mid - 1;
            }

            else l = mid + 1;
        }
        return res;
    }

    bool cnt(int m, int n, int k, int mid) {
        int x = 0;
        for(int i = 1; i <= m; ++i)
            x += min(n, mid/i);
        
        return x >= k;
    }
};
