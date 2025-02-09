class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;

        while( fast != nullptr && fast->next != nullptr) {
            
            if(fast == slow)
                return true;
            else {
                fast = fast->next->next;
                slow = slow->next;
            } 
        }

        return false;
    }
};
