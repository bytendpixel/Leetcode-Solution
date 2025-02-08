class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int ans=0;
        int c=1;
        int d=(r-l);
    while(l!=0 && r!=0){
        if((l&1) && (r&1) && (d)<=c){
            ans=ans|c;
        }
        c=c<<1;
        l=l>>1;
        r=r>>1;
    }
    return ans;
    }
};
