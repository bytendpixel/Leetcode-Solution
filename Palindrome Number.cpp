class Solution {
public:
    bool isPalindrome(int x) {
     
   long long reverseNum=0;
   int duplicate=x;
       
        while(x>0){
            int lastdigit=x%10;
            
             reverseNum=(reverseNum*10)+lastdigit;
              x=x/10;
        }
        //return reverseNum;
        if(duplicate==reverseNum) return true;
        return false;
    }

    
};
