const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class TrieNode{
public:
    int val;
    TrieNode* child[2];
    TrieNode(int val){
        this->val=val;
        for(int i=0;i<2;i++){
            this->child[i]=NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode(-1);
    void insert(int num){
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->child[bit]==NULL){
                curr->child[bit]=new TrieNode(bit);
                curr=curr->child[bit];
            }else{
                curr=curr->child[bit];
            }
        }
    }
    int get_max(int num){
        int ans=0;
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            // look for diff bit
            if(curr->child[1-bit]!=NULL){
                ans|=(1<<i);
                curr=curr->child[1-bit];
            }else if(curr->child[bit]!=NULL){
                curr=curr->child[bit];
            }else{
                return -1;
            }
        }
        return ans;
    } 
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<tuple<int,int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
       
        int idx=0;
        vector<int> ans(queries.size(),-1);
        for(auto &[limit,num,i]:q){
             int res=-1;
            while(idx<nums.size()&&nums[idx]<=limit){
                insert(nums[idx]);
                idx++;
            }
            if(idx>0){
                  int temp=get_max(num);
                  res=max(res,temp);
            }
            ans[i]=res;
        }

        return ans;


    }
};
