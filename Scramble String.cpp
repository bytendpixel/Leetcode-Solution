class Solution {
public:
    int dp[31][31][31];
    bool solve(string &s1, string &s2, int i, int j, int len){
        if(len == 1)
            return s1[i] == s2[j];
        if(dp[i][j][len] != -1)
            return dp[i][j][len];
        bool ans = false;
        for(int k = 1 ; k < len ; k++){
            ans |= solve(s1,s2,i,j,k) && solve(s1,s2,i+k,j+k,len-k);
            ans |= solve(s1,s2,i,len+j-k,k) && solve(s1,s2,i+k,j,len-k);
            if(ans)
                break;
        }
        return dp[i][j][len] = ans;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1,s2,0,0,n);
    }
};
