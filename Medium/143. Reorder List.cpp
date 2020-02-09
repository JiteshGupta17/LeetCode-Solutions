
void reorderList(ListNode* head) {
    if (!head) return;
    
    // Find the middle which is going to be slow
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Cut the middle and reverse the second half
    ListNode* sec = slow->next;
    slow->next = NULL;
    sec = reverseList(sec);

    // Merge the two lists
    ListNode* cur = head;
    while (sec)
    {
        ListNode* nxt = cur->next;
        ListNode* nxtsec = sec->next;

        cur->next = sec;
        sec->next = nxt;

        cur = nxt;
        sec = nxtsec;
    }

}

ListNode* reverseList(ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    ListNode* cur = head;
    ListNode* recAns = reverseList(head->next);

    cur->next->next = cur; // As cur->next still stores the adress of its next node
    cur->next = NULL;

    return recAns;
}
