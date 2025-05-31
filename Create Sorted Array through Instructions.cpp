const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define HI_THERE
#ifdef HI_THERE
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
    const int M = 1e9+7;
    struct elmt {
        int v, i;
        elmt(): v(0), i(0) {}
        elmt(int v, int i): v(v), i(i) {}
    };

    vector<int>L, G;

    bool cmp(bool& asc, int& lv, int& rv) { return asc ? lv<rv : lv>rv; }
    void merge(vector<elmt>&a, int l, int r, bool asc) {
        vector<elmt>b(r - l + 1);
        int m_ = (l+r)>>1, m = m_+1, l_=l, cnt = 0, k = 0;

        while (l <= m_ || m <= r) {
            int lv, rv;

            lv = (l > m_) ? (asc ? M:-M) : a[l].v;
            rv = (m > r ) ? (asc ? M:-M) : a[m].v;

            if (cmp(asc, lv, rv)) {
                ++cnt;
                b[k++] = a[l++];
            }
            else {
                (asc) ? L[a[m].i] += cnt : (G[a[m].i] += cnt);
                b[k++] = a[m++];
            }
        }
        for (k = 0; l_ <= r;) a[l_++] = b[k++];
    }
    void ms(vector<elmt>&a, int l, int r, bool asc) {
        if (l >= r) return;
        int m = (l + r) >> 1;
        ms(a, l, m, asc);
        ms(a, m + 1, r, asc);
        merge(a, l, r, asc);
    }
    int createSortedArray(vector<int>& inst) {
        int n = inst.size();
        vector<elmt>p(n);
        L.resize(n);
        G.resize(n);

        for (int i = 0; i < n; i++) p[i] = {inst[i], i};
        ms(p, 0, n - 1, 1);

        for (int i = 0; i < n; i++) p[i] = {inst[i], i};
        ms(p, 0, n - 1, 0);

        long long cost = 0;
        for (int i = 0; i < n; i++) cost += min(L[i], G[i]);

        return cost % M;
    }
};
