class Solution {
public:
    // Hamiltonian path solution using 0 as first digit for each prefix
    string crackSafe(int n, int k) {
        unordered_map<string, int> m;
        string ans = "";
        for (int i = 0; i < n - 1; i++)
            ans += '0';
        for (int i = 0; i < pow(k, n); i++) {
            string temp = ans.substr(ans.size() - (n - 1));
            m[temp] = (m[temp] + 1) % k;
            ans += ('0' + m[temp]);
        }
        return ans;
    }
};
