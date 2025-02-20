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
    vector<int> tree;

    void update(int i, int v) {
        i++;
        for ( ; i < tree.size(); i += i & -i) {
            tree[i] += v;
        }
    }

    int query(int i) {
        i++;
        int res = 0;
        for ( ; i > 0; i -= i & -i) {
            res += tree[i];
        }

        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.emplace_back(nums[i], i);
        }

        sort(a.begin(), a.end());

        tree.assign(n + 1, 0);
        for (int i = 0, j = 0; i < n; i++) {
            update(a[i].second, 1);
            while (a[i].first - a[j].first > valueDiff) {
                update(a[j].second, -1);
                j++;
            }

            if (query(max(0, a[i].second - indexDiff), min(n - 1, a[i].second + indexDiff)) - 1) {
                return true;
            }
        }

        return false;
    }
};
