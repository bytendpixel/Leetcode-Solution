class Solution {
public:
    struct TrieNode {
        char ch;
        vector<TrieNode*> child;
        bool isEndOfWord;
        
        TrieNode (char cur) {
            ch = cur;
            isEndOfWord = false;
            child = vector<TrieNode*>(26, nullptr);
        }
    };

    void add(TrieNode * root, string word) {
        TrieNode * cur = root;
        int n = word.size();
        for (int i = 0; i < n; i ++) {
            if (cur ->child[word[i] - 'a'] == nullptr) {
                TrieNode * temp = new TrieNode (word[i]);
                cur ->child[word[i] - 'a'] = temp;
            }
            cur = cur -> child[word[i] - 'a'];
        }
        cur -> isEndOfWord = true;
    }
    TrieNode * buildTrie(vector<string> & words) {
        TrieNode * root = new TrieNode('.');
        for (string word: words) {
            add(root, word);
        }
        return root;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        map<int, vector<string>> curs;
        
        s = "." + s;
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        TrieNode * root = buildTrie(wordDict);

        curs[0].push_back("");

        for (int i = 1; i < n; i ++) {
            if (dp[i-1] == true) {
                TrieNode * cur = root -> child[s[i] - 'a'];
                int j = i;
                while (cur != nullptr && cur -> ch == s[j]) {
                    if (cur -> isEndOfWord) {
                        dp[j] = true;
                        vector<string> tempv;
                        string toadd = s.substr(i, j-i+1);
                        for (string prev: curs[i-1]) {
                            if (prev.empty()) {
                                curs[j].push_back(toadd);
                            }
                            else 
                                curs[j].push_back(prev + " " + toadd);
                        }
                    }
                    j ++;
                    if (j == n) break;
                    cur = cur -> child[s[j] - 'a'];
                }
            }
        }
        // for (auto it: curs[n-1]) {
        //     ans.push_back(it);
        // }
        return curs[n-1];
    }
};
