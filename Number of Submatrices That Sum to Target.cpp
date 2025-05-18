const int H = 10000000;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        char m[2*H+1];
        int cnt=0;
        vector<int> a(c, 0);
        fill(m, m+2*H + 1, 0);
        m[H]=1;
        for (int i1=0; i1<r; i1++)
        {
            fill(a.begin(), a.end(), 0);
            for (int i2=i1; i2<r; i2++)
            {
                for (int j=0; j<c; j++)
                    a[j]+=matrix[i2][j];

                int s = 0;
                for (int j=0; j<c; j++)
                {
                    s+=a[j];
                    cnt+=m[s-target+ H];
                    m[s + H]++;
                }
                s=0;
                for (int j=0; j<c; j++)
                {
                    s+=a[j];
                    m[s + H]--;
                }
            }
        }
        return cnt;
    }
};
