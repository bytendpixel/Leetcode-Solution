int mp[2652], *zp[2652], zc[2652], step, mk;

int dfs(int *p) {
    *p = 2;
    int res = 0;
    for (int *nb : {p-step, p-1, p+1, p+step}) {
        int v = *nb;
        if (v == mk || v > 1) continue;
        if (v <= 0) *nb = mk, ++res; else res += dfs(nb);
    }
    return res;
}
int dfs2(int *p) {
    *p = 1000;
    int res = 0;
    for (int *nb : {p-step, p-1, p+1, p+step}) {
        int v = *nb;
        if (v == 2) res += dfs2(nb); else if (v <= 0) ++res, *nb = 0;
    }
    return res;
}
void dfs3(int *p) {
    *p = 1;
    for (int *nb : {p-step, p-1, p+1, p+step}) {
        int v = *nb;
        if (v == 2) dfs3(nb); else if (v <= 0) *nb = 1;
    }
}
class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
      step = isInfected[0].size() + 1; mk = 0;
        {
            int *p = mp+step;
            fill(mp, p, 1000);
            for (const auto &r : isInfected) {
                for (int x : r) *p++ = x;
                *p++ = 1000;
            }
            fill(p, p+step, 1000);
        }
        int *lo = mp+step, *hi = lo + step*isInfected.size(), res = 0;
        while(1) {
            int nb = 0;
            for (int *p = lo; p != hi; ++p) if (*p == 1) zp[nb] = p, --mk, zc[nb++] = dfs(p);
            if (nb == 0) break;

            int best = 0;
            for (int i = 1; i < nb; ++i) if (zc[i] > zc[best]) best = i;
            if (!zc[best]) break;
            res += dfs2(zp[best]);

            for (int *p = lo; p != hi; ++p) if (*p == 2) dfs3(p);
        }
        return res;  
    }
};
