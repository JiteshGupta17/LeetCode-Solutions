// Iterative
ListNode* deleteDuplicates(ListNode* head) {

    ListNode* DummyHead = new ListNode(0);
    ListNode* prev = DummyHead;
    DummyHead->next = head;
    ListNode* cur = head;

    while (cur)
    {
        int data = cur->val;

        bool f = false;

        while (cur->next && cur->next->val == data)
        {
            cout << cur->next->val;
            f = true;
        }

        prev->next = cur;
        prev = cur;

        cur = cur->next;

    }

    prev->next = NULL;

    return DummyHead->next;
}

// Recursive
ListNode* deleteDuplicates(ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    int data = head->val;
    ListNodeNode*cur = head;

    // if next not same then head will be there in the ans
    if (head->next && head->next->val != data)
    {
        head->next = deleteDuplicates(head->next);
        return head;
    }

    while (head->next && head->next->val == data)
    {
        head = head->next;
    }

    cur->next = deleteDuplicates(head->next);
    return head;
}
