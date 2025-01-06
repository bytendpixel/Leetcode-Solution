class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        vector<string> list;
        string current = "";
        auto start = products.begin();
        for (char c : searchWord)
        {
            current += c;
            list.clear();
            for (auto iter = start; iter != products.end(); ++iter)
            {
                if (list.size() == 3) break;
                if (iter->starts_with(current))
                {
                    if (list.empty()) start = iter;
                    list.push_back(*iter);
                }
            }
            result.push_back(list);
        }
        return result;
    }
};
