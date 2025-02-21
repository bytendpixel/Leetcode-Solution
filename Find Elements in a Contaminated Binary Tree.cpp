class FindElements {
private:
    unordered_set<int> seen;
public:
    FindElements(TreeNode* root) {
        if (root) { 
            root->val = 0; 
            bfs(root);
        }
    }

    bool find(int target) {
        return seen.count(target);
    }

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int val = node->val; 
            seen.insert(val);    

            if (node->left) {
                node->left->val = 2 * val + 1; 
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = 2 * val + 2;
                q.push(node->right);
            }
        }
    }
};
