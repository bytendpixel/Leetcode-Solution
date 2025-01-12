class Solution {
public:
    int romanToInt(string s) {
    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        char cur_letter = s.at(i);

        switch (cur_letter) {
            case 'I': 
            {
                if (i != s.length() - 1) {
                    if (s.at(i+1) == 'V')
                    {
                        sum += 4;
                        i++;
                    }
                        
                    else if (s.at(i+1) == 'X') {
                        sum += 9;
                        i++;
                    }
                    else
                        sum += 1;
                }
                else {
                    sum += 1;
                }
                break;
            }
            case 'V':
            {
                sum += 5;
                break;
            }
            case 'X':
            {
                if (i != s.length() - 1) {
                    if (s.at(i+1) == 'L') {
                        sum += 40;
                        i++;
                    }
                        
                    else if (s.at(i+1) == 'C') {
                        sum += 90;
                        i++;
                    }  
                    else
                        sum += 10;
                }
                else {
                    sum += 10;
                }
                
                break;
            }
            case 'L':
            {
                sum += 50;
                break;
            }
            case 'C':
            {
                if (i != s.length() - 1) {
                    if (s.at(i+1) == 'D') {
                        sum += 400;
                        i++;
                    }
                        
                    else if (s.at(i+1) == 'M')
                    {
                        sum += 900;
                        i++;
                    }                    
                    else
                        sum += 100;
                }
                else {
                    sum += 100;
                }
                break;
            }
            case 'D':
            {
                sum += 500;
                break;
            }
            case 'M':
            {
                sum += 1000;
                break;
            }
            default: break;
        }
    } 

    return sum;
    }
};
