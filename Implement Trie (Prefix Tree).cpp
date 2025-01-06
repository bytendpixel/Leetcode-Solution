class Node{
    public:
    Node* a[26];
    bool isleaf = false;
};
class Trie {
public:
    Node*root;
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node*r = root;
        for(int i=0;i<s.size();i++){
            if(!r->a[s[i]-'a']) 
                r->a[s[i]-'a'] = new Node();
            r = r->a[s[i]-'a'];
        }
        r->isleaf = true;
    }
    
    bool search(string s) {
        Node*r = root;
        for(int i=0;i<s.size();i++){
            if(!r->a[s[i]-'a']) return false;
            else r = r->a[s[i]-'a'];
        }
        return r->isleaf;
    }
    
    bool startsWith(string s) {
        Node*r = root;
        for(int i=0;i<s.size();i++){
            if(!r->a[s[i]-'a']) return false;
            else r = r->a[s[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
