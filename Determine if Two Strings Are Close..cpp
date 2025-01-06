class Solution {
public:
    bool closeStrings(string word1, string word2) {
         if ( word1.length() != word2.length()){
            return false;
        }else{
            int count1[26];
            int count2[26];

            for ( char ch1 : word1){
                count1[ch1 - 'a']++;
            }

            for ( char ch2 : word2 ){
                count2[ch2 - 'a']++;
            }

           for ( int i = 0 ; i < 26 ; i ++){

            if ( (count1[i] != 0 && count2[i] == 0) || ( count1[i] == 0 && count2[i] != 0)){
                return false;
            }
           }

           sort ( count1, count1 + 26);
           sort (count2, count2 + 26);



           for ( int i = 0; i < 26 ; i++){
                if ( count1[i] != count2[i]){
                    return false;
                }
           }
        }
        return true;
    }
};
