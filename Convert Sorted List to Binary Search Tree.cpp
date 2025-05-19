/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return {};
        ListNode* c = GetCenter(head, nullptr);
        TreeNode* root = new TreeNode(c->val);
        Next(root, head, c, nullptr);
        return root;
    }
private:
    ListNode* GetCenter(ListNode* head, ListNode* end){
        ListNode* p1 = head, *p2 = head;
        while(p2->next != end && p2->next->next != end){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }

    void Next(TreeNode* root, ListNode* lstart, ListNode* rstart, ListNode* end){
        if(lstart != rstart){
            ListNode* c = GetCenter(lstart, rstart);
            root->left = new TreeNode(c->val);
            Next(root->left, lstart, c, rstart);
        }
        if(rstart->next != end){
            ListNode* c = GetCenter(rstart->next, end);
            root->right = new TreeNode(c->val);
            Next(root->right, rstart->next, c, end);
        }
    }
};
