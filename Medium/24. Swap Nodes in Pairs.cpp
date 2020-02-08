// Iterative Best 0ms
ListNode* swapPairs(ListNode* head) {

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* prev = dummyHead;
    ListNode* cur = dummyHead->next;

    // b,a,c,d,e let a and b is swapped and now is prev at 'a' and cur is 'c'
    while (cur && cur->next)
    {
        // Joining link btw a and d
        prev->next = cur->next;

        // Storing adress of e
        ListNode* forw = cur->next->next;

        // Making next of as d as c
        cur->next->next = cur;

        // Changing prev to c
        prev = cur;

        // Joining c and e
        cur->next = forw;

        // Making cur as e
        cur = forw;
    }

    return dummyHead->next;


}

// Recursive 4ms
ListNode* swapPairs(ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    ListNode* n = head->next;

    ListNode* recAns = swapPairs(n->next);

    head->next = recAns;
    n->next = head;

    return n;

}
