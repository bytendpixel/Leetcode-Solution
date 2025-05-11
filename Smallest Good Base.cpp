class Solution {
public:
    string smallestGoodBase(string n_str) {
        long long n = stoll(n_str);
        int max_m = log2(n);  // maximum possible value of m

        for (int m = max_m; m >= 1; --m) {
            long long left = 2, right = pow(n, 1.0 / m) + 1;
            while (left <= right) {
                long long k = left + (right - left) / 2;
                long long sum = 1, cur = 1;
                for (int i = 1; i <= m; ++i) {
                    cur *= k;
                    sum += cur;
                    if (sum > n) break;  // early exit
                }

                if (sum == n) return to_string(k);
                else if (sum < n) left = k + 1;
                else right = k - 1;
            }
        }

        return to_string(n - 1);  // fallback: base n-1 is always valid (1 + 1)
    }
};
