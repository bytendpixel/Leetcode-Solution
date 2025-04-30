class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>>v;
        dfs(root, v, 0, 0);
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        for (int i = 0; i < v.size(); i++){
            int val = get<2>(v[i]);
            if (i>0 && get<0>(v[i]) == get<0>(v[i-1])){
                res.back().push_back(val);
            } else {
                vector<int> temp;
                temp.push_back(val);
                res.push_back(temp);
            }
        }
        return res;
    }
    void dfs(TreeNode* root, vector<tuple<int, int, int>>& v, int row, int col){
        if (!root){
            return;
        }
        v.push_back({col, row, root->val});
        dfs(root->left, v, row+1, col-1);
        dfs(root->right, v, row+1, col+1);
        return;
    }
};
