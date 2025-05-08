class Solution {
public:
    int numOfWays(int n) {
        const int M=1e9+7;
        long long a=6,b=6;
        for(int i=2;i<=n;i++){
            long long newa,newb;
            newa=(3*a+2*b)%M;
            newb=(2*a+2*b)%M;
            a=newa;
            b=newb;
        }
        return (a+b)%M;
    }
};
