class Solution {
public:
void func(int ind,vector<vector<int>>&ans,vector<int>&arr,vector<int>&ds){
    if(ind==arr.size())
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(arr[ind]);
    func(ind+1,ans,arr,ds);
    ds.pop_back();
    func(ind+1,ans,arr,ds);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        func(0,ans,nums,ds);
        return ans;
    }
};
