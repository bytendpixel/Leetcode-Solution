class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        long long res = 1;
        for (int i = 1; i <= n; ++i) {
            res = res * i % MOD;               // i! for pick-ups
            res = res * (2 * i - 1) % MOD;      // (2i - 1) ways to place delivery
        }
        return res;
    }
};
