#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    bitset<10001> is_square=0;
    void test_square(){
        for(int i=1; i<=100; i++)
            is_square[i*i]=1;
    }
    int numSquares(int n) {

        //Use Lagrange's four-square theorem and Legendre's three-square theorem
        while (n%4==0) n/=4;
        if (n%8==7) return 4;

        test_square();
        if (is_square[n]) return 1;
        
        double&& sqrt_n=sqrt(n);
        for(int i=1; i<=sqrt_n; i++)
        {
            int y=n-i*i;
            if (is_square[y]) return 2;//2 squares;
        }
       
        return 3;
    }
};
