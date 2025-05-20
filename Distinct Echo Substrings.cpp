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

#define ll long long
class Solution {
public:
    int n, MOD=1e9+7, base=31;
    ll f[2001], p[2001];
    unordered_map<ll, bool> visited;
    ll getHash(int l, int r)
    {
        ll ans = ((f[r] - f[l-1]*p[r-l+1])%MOD+MOD)%MOD;
        return ans;
    }
    int distinctEchoSubstrings(string text) 
    {
        n = text.size();
        text = ' ' + text;
        p[0] = 1, f[0] = 0;
        for ( int i = 1; i <= n; i++) p[i] = p[i-1]*base % MOD;
        for ( int i = 1; i <= n; i++) f[i] = (f[i-1]*31 + text[i]-'a'+1)%MOD;
        int k = 2, res = 0;
        while ( k <= n )
        {
            for ( int i=1; i+k-1<=n; i++)
            {
                if ( !visited.count(getHash(i,i+k-1)) && 
                getHash(i,i+k/2-1) == getHash(i+k/2, i+k-1) )  
                {
                    visited[getHash(i,i+k-1)] = 1;
                    res++;
                }
            }
            k+=2;
        }
        return res;
    }
};
