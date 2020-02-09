// Iterative
ListNode* reverseList(ListNode* head) {
    ListNode*  prev = NULL;
    ListNode* cur = head;
    ListNode* nxt;

    while (cur)
    {
        // Storing the next
        nxt = cur->next;

        // Joining with the back
        cur->next = prev;

        // Updating
        prev = cur;
        cur = nxt;
    }

    head = prev;

    return head;
}

// Recursive
ListNode* reverseList(ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    ListNode* cur = head;
    ListNode* recAns = reverseList(head->next);

    cur->next->next = cur; // As cur->next still stores the adress of its next node
    cur->next = NULL;

    return recAns;
}
