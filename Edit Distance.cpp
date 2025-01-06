class Solution {
public:
    int f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= f(i-1,j-1,s1,s2,dp);
        }else{
            int ch1=1+f(i-1,j,s1,s2,dp);
            int ch2=1+f(i,j-1,s1,s2,dp);
            int ch3=1+f(i-1,j-1,s1,s2,dp);
            return dp[i][j]=min({ch1,ch2,ch3});
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2,dp);
    }
};
