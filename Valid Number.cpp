class Solution {
public:
    bool isNumber(string s) {
        for(int i = 1; i < s.size(); ++i){
            if(((s[i]=='-')||(s[i]=='+')) && ((s[i-1]=='-')||(s[i-1]=='+'))) return false;
        }
        if(s[s.size()-1]=='-'||s[s.size()-1]=='+')return false;
        int idx = 0;
        if(s[idx]=='-' || s[idx]=='+') idx++;
        int numidx = idx;
        bool n = false;
        bool e = false;
        bool dot = false;
        bool sign = false;
        while(idx<s.size()){
            if(s[idx]=='.'){
                if(dot) return false;
                dot = true;
            }else if(s[idx]=='e'||s[idx]=='E'){
                if(e || !n) return false;
                e = true;
                n = false;
                dot = false;
            }else if(s[idx]>='0'&&s[idx]<='9'){
                if(e && dot) return false;
                n = true;
            }else if(s[idx]=='-'||s[idx]=='+'){
                if(n || (dot && !n)) return false;
            }else{
                return false;
            }
            idx++;
        }
        if(e&&!n || dot&&!n || e&&dot) return false;
        return true;
    }
};
