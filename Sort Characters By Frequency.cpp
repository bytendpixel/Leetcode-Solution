class Solution {
private:
    vector<pair<char, int>>
    sortMapByValue(const unordered_map<char, int>& hash) {
        vector<pair<char, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 if (a.second != b.second)
                     return a.second > b.second;
                 return a.first < b.first;
             });

        return vec;
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> map1;
        for (char c : s)
            map1[c]++;
        string ans = "";
        vector<pair<char, int>> sortedVec = sortMapByValue(map1);
        for (int i = 0; i < sortedVec.size(); i++) {
            int cnt = 1;
            while (cnt <= sortedVec[i].second) {
                ans += sortedVec[i].first;
                cnt++;
            }
        }
        return ans;
    }
};
