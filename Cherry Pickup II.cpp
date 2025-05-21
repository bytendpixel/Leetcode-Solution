class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        //just do a dp
        int dp[2][75][75];
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<2;i++){
            for(int j=0;j<cols;j++){
                for(int k=0;k<cols;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        dp[0][0][cols-1]=grid[0][0]+grid[0][cols-1];

        for(int i=1;i<rows;i++){
            for(int j1=0;j1<cols; j1++){
                for(int j2=j1+1;j2<cols;j2++){
                    int maxi=INT_MIN;
                    for(int x=-1;x<=1;x++){
                        if( ((j1+x)<0) or ( (j1+x)>=cols) )continue;
                        for(int y=-1;y<=1;y++){
                            if((j2+y<0) or (j2+y>=cols) )continue;
                            maxi=max(maxi, dp[(i+1)%2][j1+x][j2+y]);
                        }
                    }
                    dp[i%2][j1][j2]=(maxi==INT_MIN) ? INT_MIN : grid[i][j1]+grid[i][j2]+ maxi;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<cols;i++){
            for(int j=i+1;j<cols;j++){
                if(dp[(rows+1)%2][i][j]> ans) ans=dp[(rows+1)%2][i][j];
            }
        }
        return ans;
    }
};
