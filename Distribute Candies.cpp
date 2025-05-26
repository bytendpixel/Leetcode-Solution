class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int c=n/2;
        int types=0;
        bool hashset[200001]={0};
        for(int i=0; i<n;i++){
            int idx=candyType[i]+100000;
            if(!hashset[idx]){
                hashset[idx]=true;
                types++;
            }
        }

        return (c<types)?c:types;
        
        

        
    }
};
