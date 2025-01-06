class Solution {
public:
    string removeStars(string s) {
      // string ans;
         std::vector<char> ans; // Keep this as a vector of chars
        int n=s.size()-1;
        int i=0;
        for(char c:s){
            if(c=='*'){
                if(!ans.empty()){
              ans.pop_back();
                }
            }
     //ans.push_back(std::string(1, s[i]));
   
        else{ans.push_back(c); // Push the character directly
           }
        }
          return std::string(ans.begin(), ans.end()); 
    }
};
