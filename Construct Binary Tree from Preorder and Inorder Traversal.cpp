class Solution {
public:
    TreeNode* build(vector<int>& preorder, int &preorder_ind, unordered_map<int,int>&inorder_map, int in_left, int in_right){
        if(in_left>in_right) return nullptr;
        int val=preorder[preorder_ind++];
        TreeNode* root= new TreeNode(val);
        int inorder_index=inorder_map[val];
        root->left=build(preorder,preorder_ind,inorder_map,in_left,inorder_index-1);
        root->right=build(preorder,preorder_ind,inorder_map,inorder_index+1,in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inorder_map;
        int preorder_ind=0;
        for(int i=0;i<inorder.size();i++){
            inorder_map[inorder[i]]=i;
        }
        return build(preorder,preorder_ind,inorder_map,0,inorder.size()-1);
    }
};
