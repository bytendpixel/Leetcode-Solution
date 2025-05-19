class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& a) {
        int n = a[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        dp[n-1][n-1] = {0, 1};
        vector<int> ans(2);
        int c1 = 0, c2 = 0;
        for(int i = n-2; i>=0; i--){
            
            if(a[n-1][i]=='X'){
                c1 = 1;
            }
            if(!c1){
                dp[n-1][i].first = dp[n-1][i+1].first + a[n-1][i] - '0';
                dp[n-1][i].second = 1;
            }
            
            if(a[i][n-1]=='X'){
                c2 = 1;
            }
            if(!c2){
                dp[i][n-1].first = dp[i+1][n-1].first + a[i][n-1] - '0';
                dp[i][n-1].second = 1;
            }
        }

        for(int i = n-2; i>=0; i--){

            for(int j = n-2; j>=0; j--){
                if(a[i][j] == 'X') continue;
                if(i or j)dp[i][j].first = a[i][j] - '0';
                
                int m = 0, ways = 0;

                if(m == dp[i+1][j].first){
                    m = dp[i+1][j].first;
                    ways += dp[i+1][j].second%(1000000000+7);
                }

                if(m<dp[i+1][j].first){
                    m = dp[i+1][j].first;
                    ways = dp[i+1][j].second%(1000000000+7);
                }

                if(m == dp[i][j+1].first){
                    m = dp[i][j+1].first;
                    ways += dp[i][j+1].second%(1000000000+7);
                }

                if(m<dp[i][j+1].first){
                    m = dp[i][j+1].first;
                    ways = dp[i][j+1].second%(1000000000+7);
                }

                if(m == dp[i+1][j+1].first){
                    m = dp[i+1][j+1].first;
                    ways += (dp[i+1][j+1].second)%(1000000000+7);
                }

                if(m<dp[i+1][j+1].first){
                    m = dp[i+1][j+1].first;
                    ways = dp[i+1][j+1].second%(1000000000+7);
                }
                if(!ways) dp[i][j] = {0, 0};
                
                else{
                    dp[i][j].first = (m + dp[i][j].first);
                    dp[i][j].second = ways%(1000000000+7);
                }
            }
        }
        
        ans[0] = dp[0][0].first; ans[1] = dp[0][0].second;
        return ans;
    }
};
