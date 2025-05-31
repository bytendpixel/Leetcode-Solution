using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
#define pb push_back
#define MOD 1000000007
class Solution {
public:
  
  int checkWays(vector<vector<int>> &pairs) {
    vi vC(501,0);
    vi vP(505,0);
    vi adj[501];
    int ans = 1, root = 0;
    for (auto &i : pairs) {
      vC[i[0]]++;
      vC[i[1]]++;
    }
    for (auto &i : pairs) {
      if (vC[i[0]] < vC[i[1]])
        adj[i[0]].pb(i[1]);
      else
        adj[i[1]].pb(i[0]);
    }
    for (int l = 1; l < 501; l++) {
      if (vC[l] == 0)
        continue;
      adj[l].pb(l);
      sort(adj[l].begin(), adj[l].end(), [&](int a, int b) {
        return vC[a] == vC[b] ? a < b : vC[a] > vC[b];
      });
      for (int i = 1; i < adj[l].size(); i++) {
        int v = adj[l][i];
        if (vC[v] == vC[adj[l][i - 1]])
          ans = 2;
        if (vP[v] == 0)
          vP[v] = adj[l][i - 1];
        else if (vP[v] != adj[l][i - 1])
          return 0;
      }
      if (!root)
        root = adj[l][0];
      else if (root != adj[l][0])
        return 0;
    }
    return ans;
  }
};
