class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int arr[26]={0};
        string cheese = "fadsdafsdfsadfasdfasdfsadfasdfas";
        for(int i = 0;i<licensePlate.size();i++){
            if(licensePlate[i]>=65&&licensePlate[i]<=90){
                arr[licensePlate[i]-65]++;
            }
            if(licensePlate[i]>=97&&licensePlate[i]<=122){
                arr[licensePlate[i]-97]++;
            }
        }
        for(int i = 0;i<words.size();i++){
            bool d = true;
            int fur[26] = {0};
            for(int j = 0;j<words[i].size();j++){
                if(words[i][j]>=65&&words[i][j]<=90){
                    fur[words[i][j]-65]++;
                }   
                if(words[i][j]>=97&&words[i][j]<=122){
                    fur[words[i][j]-97]++;
                }
            }
            for(int i = 0;i<26;i++){
                if(fur[i]<arr[i]){
                    d= false;
                }
            }
            if(d&&cheese.size()>words[i].size()){
                cheese = words[i];
            }
        }
        return cheese;
    }
};
