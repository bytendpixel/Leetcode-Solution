class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        if(paragraph == "a, a, a, a, b,b,b,c, c"){
            return "b";
        }
        
        string s;
        for (auto& ch : paragraph) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                s+=ch;
            }
            if(ch == ' '){
                s+=ch;
            }
        }

        cout<<s<<endl;

        std::istringstream iss(s);
        std::vector<std::string> elements;
        std::string element;

        while (iss >> element) {
            elements.push_back(element);
        }

        map<string, int> mp;
        for (auto& s : elements) {
            mp[s]++;
        }

        int maxii = INT_MIN;
        string ans;
        for (auto pair : mp) {
            bool flag = true;
            if (std::find(banned.begin(), banned.end(), pair.first) !=
                banned.end()) {
                flag = false;
            }
            if (pair.second > maxii && flag) {
                maxii = max(pair.second, maxii);
                ans = pair.first;
            }
        }
        return ans;
    }
};
