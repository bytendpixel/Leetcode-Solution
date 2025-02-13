#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        
        
        if (dict.find(endWord) == dict.end())
            return res;

        
        unordered_map<string, vector<string>> parents;
        
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);
        
    
        while (!currentLevel.empty() && parents.find(endWord) == parents.end()) {
            
            for (const auto &word : currentLevel)
                dict.erase(word);
            
            unordered_set<string> nextLevel;
          
            for (const auto &word : currentLevel) {
                string s = word;
                for (int i = 0; i < s.size(); ++i) {
                    char original = s[i];
                 
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue; 
                        s[i] = c;
                       
                        if (dict.find(s) != dict.end()) {
                            nextLevel.insert(s);
                            
                            parents[s].push_back(word);
                        }
                    }
                    s[i] = original; 
                }
            }
            currentLevel = nextLevel;
        }

       
        if (parents.find(endWord) == parents.end())
            return res;

        
        vector<string> path;
        function<void(const string&)> dfs = [&](const string &word) {
            path.push_back(word);
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            } else {
                for (const auto &parent : parents[word])
                    dfs(parent);
            }
            path.pop_back();
        };
        dfs(endWord);
        return res;
    }
};
