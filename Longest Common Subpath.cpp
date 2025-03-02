class Solution {
public:
    const long long MOD = 100000000007;
    const long long base = 100007;

    bool isValid(vector<vector<int>>& paths, int k) {
        unordered_map<long long,int> hashes; 
        long long hash = 0, h = 1;
        for (int i = 0; i < k; ++ i) {
            hash = (hash * base + paths[0][i]) % MOD;
            if (i > 0) h = (h * base) % MOD;
        }
        hashes[hash] = 1;
        for (int i = k; i < paths[0].size(); ++ i) {
            hash = ((((hash - h * paths[0][i - k]) % MOD + MOD) * base) % MOD + paths[0][i]) % MOD;
            hashes[hash] = 1;
        }
        for (int i = 1; i < paths.size(); ++ i) {
            hash = 0;
            for (int j = 0; j < k; ++ j) hash = (hash * base + paths[i][j]) % MOD;
            if (hashes.count(hash) && hashes[hash] == i) ++ hashes[hash];
            for (int j = k; j < paths[i].size(); ++ j) {
                hash = ((((hash - h * paths[i][j - k]) % MOD + MOD) * base) % MOD + paths[i][j]) % MOD;
                if (hashes.count(hash) && hashes[hash] == i) ++ hashes[hash];
            }
        }
        for (const auto& [_, cnt] : hashes) {
            if (cnt == paths.size()) return true;
        }
        return false;
    }

    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l = 1, r = INT_MAX, m, res = 0;
        for (const vector<int>& p : paths) r = min(r, int(p.size()));
        while (l <= r) {
            m = (l + r) / 2;
            if (isValid(paths, m)) {
                l = m + 1;
                res = max(res, m);
            } else r = m - 1;
        }
        return res;
    }
};
