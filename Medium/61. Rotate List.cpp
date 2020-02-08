ListNode* rotateRight(ListNode* head, int k) {
    
    ListNode* DummyHead = new ListNode(0);
    DummyHead->next = head;

    ListNode* tail = DummyHead;
    ListNode* cur = head;

    int len = 0;
    while (cur)
    {
        len++;
        tail = tail->next;
        cur = cur->next;
    }
    if (len == 0) return NULL;
    k = k % len;
    //kth node from end becomes the start node

    ListNode* prev = DummyHead;

    // Fast slow trick can also be used
    // but we have already calculated len and tail which can be used now
    for (int i = 0; i < len - k; i++)
    {
        prev = prev->next;
    }

    tail->next = head; // Joining tail and head
    head = prev->next; // New head
    prev->next = NULL; // Breaking the list


    return head;
}


// Using fast and slow
ListNode* rotateRight(ListNode* head, int k) {

    ListNode* cur = head;

    int len = 0;
    while (cur)
    {
        len++;
        cur = cur->next;
    }
    if (len == 0) return NULL;
    int k = k % len;
    //kth node from end becomes the start node

    ListNode* DummyHead = new ListNode(0);
    DummyHead->next = head;
    ListNode* prev = DummyHead;

    ListNode* fast = head;

    while (k--)
    {
        fast = fast->next;
    }

    while (fast && fast->next)
    {
        prev = prev->next;
        fast = fast->next;
    }

    fast->next = head;

    head = prev->next;

    prev->next = NULL;

    return head;


}
