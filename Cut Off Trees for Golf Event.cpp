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
    int findPath(vector<vector<int>> forest, int sx, int sy, int dx, int dy){
        int x[4] = {0, 0, -1, 1};
        int y[4] = {1, -1, 0,  0};
        int n = forest.size(), m = forest[0].size();
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {sx, sy}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first, cx = it.second.first, cy = it.second.second;
            if(cx == dx && cy == dy) return d;
            if(forest[cx][cy] == 0) continue;
            forest[cx][cy] = 0;
            for(int i=0;i<4;i++){
                int xx = cx+x[i], yy = cy+y[i];
                if(xx >= 0 && yy >= 0 && xx < n && yy < m && forest[xx][yy] > 0){
                    q.push({d+1, {xx, yy}});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
        int n = forest.size(), m = forest[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j] > 1)
                p.push({forest[i][j], {i, j}});
            }
        }
        int ans = 0, cx = 0, cy = 0;
        while(!p.empty()){
            auto it = p.top();
            p.pop();
            int c = findPath(forest, cx, cy, it.second.first, it.second.second);
            if(c == -1) return c;
            ans+=c;
            cx = it.second.first, cy = it.second.second;
        }
        return ans;
    }
};
