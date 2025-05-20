class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int left = 0, right = 1;
        vector<int> lps(n,0);

        while(right < n){
            if(s[right] == s[left]){
                lps[right] += left+1;
                right++;
                left++;
            } else {
                if(left == 0){
                    lps[right] = 0;
                    right++;
                } else {
                    left = lps[left-1];
                }
            }
        }

        return s.substr(0, lps[n-1]);
    }
};
