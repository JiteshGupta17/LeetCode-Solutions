//Recursive
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    ListNode* c ;

    if (l1->val <= l2->val)
    {
        c = new ListNode (l1->val);
        c->next = mergeTwoLists(l1->next, l2);
    }
    else {
        c = new ListNode (l2->val);
        c->next = mergeTwoLists(l1, l2->next);
    }

    return c;
}

//Iterative
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
        }

        cur = cur->next;
    }

    while (l1)
    {
        cur->next = new ListNode(l1->val);
        cur = cur->next;
        l1 = l1->next;
    }

    while (l2)
    {
        cur->next = new ListNode(l2->val);
        cur = cur->next;
        l2 = l2->next;
    }

    return dummyHead->next;
}

