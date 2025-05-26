/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p) return false;
        else if(!q) return false;

        if(p->val == q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root,subRoot)) return true;
        if(!root || !subRoot) return false;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
