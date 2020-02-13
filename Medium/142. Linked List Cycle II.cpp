class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast)
            {
                break;
            }
        }
        
        // No cycle
        if(slow!=fast) return NULL;
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};
