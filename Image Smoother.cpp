class Solution {
public:
int value(vector<vector<int>>& img, int i, int j) {
        int x = img[i][j];
        int n = 1;
        if (i - 1 >= 0) {
            x += img[i - 1][j];
            n++;
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            x += img[i - 1][j - 1];
            n++;
        }
        if (i - 1 >= 0 && j + 1 < img[0].size()) {
            x += img[i - 1][j + 1];
            n++;
        }
        if (j - 1 >= 0) {
            x += img[i][j - 1];
            n++;
        }
        if (j + 1 < img[0].size()) {
            x += img[i][j + 1];
            n++;
        }
        if (i + 1 < img.size()) {
            x += img[i + 1][j];
            n++;
        }
        if (i + 1 < img.size() && j - 1 >= 0) {
            x += img[i + 1][j - 1];
            n++;
        }
        if (i + 1 < img.size() && j + 1 < img[0].size()) {
            x += img[i + 1][j + 1];
            n++;
        }
        return x / n;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=value(img,i,j);
            }
        }
        return res;
    }
};
