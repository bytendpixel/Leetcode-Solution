class Solution {
public:
    bool checkPower(int n){
        if(n<1) return false;
        if(n==1) return true;
        if(n%3!=0) return false;
        return checkPower(n/3);
    }

    bool isPowerOfThree(int n) {
        return checkPower(n);
    }
};
