class Solution {
public:

    bool leq(int i, int j, vector<string> &strs){
        int n=strs.size();
        for (int k=0;k<n;k++) if (strs[k][i]>strs[k][j]) return false;
        return true;
    }

    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size(),ret=0,c[m];

        for (int i=m-1;i>=0;i--){
            c[i]=1;
            for (int j=i+1;j<m;j++) if (c[i]<c[j]+1 && leq(i,j,strs)) c[i]=c[j]+1;
            ret=max(ret,c[i]);
            //cout<<c[i]<<'\n';
        }

        return m-ret;
    }
};
