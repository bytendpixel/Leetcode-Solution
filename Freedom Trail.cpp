class Solution {
public:
int min_dist(int n,int start,int dest){
    return min(abs(dest-start),n-abs(dest-start));
}
    int findRotateSteps(string ring, string key) {
        string a=ring, k = key;
        int n = a.length(), m = k.length();
   int mp[26][100] = {{0}};
   int freq[26] = {0};
   int dp[100][100] = {{0}};

    for(int i=0;i<n;i++){
        mp[a[i] - 'a'][freq[a[i]-'a']++] = i;
    }

    for(int i=0;i<freq[k[0]-'a'];i++){
        dp[0][mp[k[0]-'a'][i]] = min_dist(n, 0, mp[k[0]-'a'][i]) + 1;
    }

    for(int i=1;i<m;i++){
        for(int j=0;j<freq[k[i]-'a'];j++){
            int res = INT_MAX;
            for(int u=0;u<freq[k[i-1]-'a'];u++){
               res = min(res, dp[i-1][mp[k[i-1]-'a'][u]] + min_dist(n, mp[k[i-1]-'a'][u], mp[k[i]-'a'][j]) + 1);
            }
            dp[i][mp[k[i]-'a'][j]] = res;

        }
    }

    int maxx =INT_MAX;
    for(int i=0;i<freq[k.back() - 'a'];i++){
        maxx = min(maxx,dp[m-1][mp[k.back()-'a'][i]]);
    }

return maxx;
    }
};
