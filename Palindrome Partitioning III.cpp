class Solution {
public:
    int dy[105][105];
    int pal[105][105];
    int N;

    void init(const string& s) {
        memset(pal, 0, sizeof(pal));
        for (int i = 0; i <= N; i++) pal[i][i] = 0;
        for (int i = 1; i < N; i++)  {
            pal[i-1][i] = (s[i] == s[i-1]) ? 0 : 1;
        }

        for (int l = 2; l < N; ++l) {
            for (int i = 0; i < N; i++) {
                if (i+l > N) break;
                pal[i][i+l] = pal[i+1][i+l-1];
                if (s[i] != s[i+l]) pal[i][i+l]++;
            }
        }
    }

    int go(int idx, int k) {
        if (k == 1) return pal[idx][N-1];
        int &ret = dy[idx][k];
        if (N-idx <= k) return 0;
        if (ret >= 0) return ret;
        for (int ni = idx; N-ni >= k; ++ni) {
            int v = pal[idx][ni] + go(ni+1, k-1);
            if (ret < 0 || ret > v) ret = v;
        }
        return ret;
    }

    int palindromePartition(string s, int k) {
        N = s.length();
        memset(dy, -1, sizeof(dy));
        init(s);
        return go(0, k);
    }
};
