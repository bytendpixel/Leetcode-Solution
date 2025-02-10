
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int i=0;
            double n=q.size();
            double sum=0;
            while(i!=n){
                TreeNode* a=q.front();
                q.pop();
               
                sum+=a->val;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                
                i++;
               
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};
