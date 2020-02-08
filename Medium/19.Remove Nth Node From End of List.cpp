ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* DummyHead = new ListNode(0);
    DummyHead->next = head;

    ListNode* fast = head;
    ListNode* slow = head;

    ListNode* prev = DummyHead;

    while (n-- && fast)
    {
        fast = fast->next;
    }

    while (fast)
    {
        prev = prev->next;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = slow->next;
    delete slow;

    return DummyHead->next;

}


// Creating the dummy head prevents the if condition of slow == head
ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (head == NULL) return head;

    ListNode* fast = head;

    while (n-- && fast)
    {
        fast = fast->next;
    }

    ListNode*slow = head;
    ListNode*prev;

    while (fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }


    if (slow == head) {
        head = slow->next;
        delete slow;
        return head;
    }

    prev->next = slow->next;
    delete slow;
    return head;

}


