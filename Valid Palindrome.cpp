class Solution {
public:
    bool isPalindrome(string s) {
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
            s[j++] = tolower(s[i]);
            }
        }
        s.resize(j);
        int num = j-1;
        for(int i = 0; i < j; i++){
           if(s[i] != s[num]) return false;
           num--;
        }
        return true;
    }
};
