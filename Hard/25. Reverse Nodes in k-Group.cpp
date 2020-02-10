
ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;

    int i = 0;
    for ( i; i < k && temp->next; i++) {
        temp = temp->next;
    }
    
    // if length is less than k
    if (i != k) return head;

    ListNode *newHead = temp->next;
    temp->next = NULL;

    ListNode *node = reverseLL(head);
    head = node;

    while (node->next) {
        node = node->next;
    }
    node->next = reverseKGroup(newHead, k);

    return head;

}

ListNode *reverseLL(ListNode *&head)
{
    ListNode *c = head;
    ListNode *p = NULL;
    ListNode *n;

    while (c != NULL)
    {
        //save the next node
        n = c->next;

        //make the current node point to prev
        c->next = p;

        //update prev and current
        p = c;
        c = n;
    }
    head = p;
    return head;
}
