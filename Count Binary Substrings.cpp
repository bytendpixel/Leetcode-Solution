class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length(),j=0,i=0,ans=0;
        int prev = 0;
        while(j<n && s[j] == s[prev]) j++;
        int cur = j;
        while(j<n){
            while(j<n && s[j] == s[cur]) ++j;
            ans += min(cur-prev,j-cur);
            prev=cur;
            cur=j;
        }
        return ans;
    }
};
