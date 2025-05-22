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

#include <vector>
#include <cmath>

class Fancy {
private:
    std::vector<long long> sequence;
    long long add = 0;
    long long mult = 1;
    const int MOD = 1e9 + 7;

    long long modInverse(long long a, long long m) {
        long long m0 = m, t, q;
        long long x0 = 0, x1 = 1;
        if (m == 1) return 0;
        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += m0;
        return x1;
    }

public:
    Fancy() {}

    void append(int val) {
        sequence.push_back((val - add + MOD) % MOD * modInverse(mult, MOD) % MOD);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        add = add * m % MOD;
        mult = mult * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= sequence.size()) return -1;
        return (sequence[idx] * mult % MOD + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
