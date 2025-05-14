class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>>st;
        unordered_map<string,int>mpp;
        st.push(mpp);
        int n=formula.length();
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>{});
                i++;
            }
            else if(formula[i]==')') {
                string x="";
                i++;
                while(i<n and isdigit(formula[i])){
                    x+=formula[i];
                    i++;
                }
                int number=1;
                if(!x.empty()) number=stoi(x);
                unordered_map<string,int>temp=st.top();
                st.pop();
                for(auto &[key,value]:temp){
                    st.top()[key] += value * number;
                }
            }
            else{
                string atom="";
                atom+=formula[i];
                i++;
                while(i<n and islower(formula[i])){
                    atom+=formula[i];
                    i++;
                }
                int num=1;
                string numm="";
                while(i<n and isdigit(formula[i])){
                    numm+=formula[i];
                    i++;
                }
                if(!numm.empty())num=stoi(numm);
                st.top()[atom]+=num;
            }
        }
        string ans="";
        map<string,int>final(st.top().begin(),st.top().end());
        for(auto &[key,value]:final){
            ans+=key;
            if(value>1)ans+=to_string(value);
        }
        return ans;
    }
};
