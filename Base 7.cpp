class Solution {
public:
    string convertToBase7 (int num) {
        if ( num == 0 ) {
            return "0";
        }

        bool negative = false;

        if ( num < 0 ) {
            num = -num;
            negative = true;
        }

        string s = "";

        while ( num > 0 ) {
            s += to_string (num % 7);

            num /= 7;
        }

        if ( negative == true ) {
            s += '-';
        }

        reverse (s.begin (), s.end ());

        return s;
    }
};
