class Solution {
    bool can_replace(string &stamp,string &target,int idx){
      bool c=false;
       for(int i=0;i<stamp.size();i++){
            if(target[idx+i]=='?')
            continue;

            else if(stamp[i]!=target[idx+i])
              return false;
            else 
                c=true;
       }

       return c;
}
public:
    vector<int> movesToStamp(string stamp, string target) {
          int n=stamp.size();
       int m=target.size();
       vector<int> ans;
       int is_change=true;
    
       while (is_change)
       {
            
              
             is_change=false;
            for(int k=0;k<=m-n;k++){
                  if(can_replace(stamp,target,k)){   
                        ans.push_back(k);
                       for(int j=k;j<k+n;j++){
                        if(target[j]!='?')
                           target[j]='?';

                           
                       }
                       is_change=true;   
                         
                  }
            }
       
       }
         for(int i=0;i<m;i++)
           if(target[i]!='?')
              return {};

       reverse(ans.begin(),ans.end());
       return ans;
    }
};
