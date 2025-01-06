class Solution {
public:
    int maxArea(vector<int>& v) {
        int l=0;
        int r=v.size()-1;
        int maxarea=0;
        int area=0;
        while(l<r){
            
            if(v[l]<v[r]){
                area=(r-l)*v[l];
                if(area>maxarea){
                    maxarea=area;
                }
                l++;
            }
            else{
                area=(r-l)*v[r];
                if(area>maxarea){
                    maxarea=area;
                }
                r--;
            }
        }
        return maxarea;
    }
};
