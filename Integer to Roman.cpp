class Solution {
public:
    string intToRoman(int num) {
        //1. create a array of all the roman letters -> 13 
        string romanSymbols[] = {"M" , "CM" , "D" , "CD" , "C" , 
                                "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
        //2. create array of values corresponds to each roman letter in above 
        int values[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};

        string ans = "";


        for(int i=0;i<13;i++) {
            //agar num >= value -> to vo value ka roman letter add karo
            //and num ko value se substract karo
            while(num >= values[i]) {
                ans += romanSymbols[i];
                num -= values[i];
            }
        }
        return ans;
    }
};
