//Method 1 - Shorter
ListNode* addTwoNumbers(ListNode * l1, ListNode * l2) {

    ListNode *PrevHead = new ListNode(0);
    ListNode *cur = PrevHead;
    int carry = 0;

    while (l1 || l2) {

        int x = (l1) ? l1->val : 0;
        int y = (l2) ? l2->val : 0;

        int sum = carry + x + y;
        carry = sum / 10;

        cur->next = new ListNode(sum % 10);
        cur = cur->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    // Eg - 5,5
    if (carry) {
        cur->next = new ListNode(carry);
    }
    return PrevHead->next;
}

// Method 2 - Longer
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    int carry = 0;
    ListNode* head;

    if (l1 || l2)
    {
        int x = 0;
        if (l1 && l2)
        {
            x = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else {
            if (l1 != NULL)
            {
                x = l1->val;
                l1 = l1->next;
            }
            else {
                x = l2->val;
                l2 = l2->next;
            }
        }
        carry = x / 10;
        x = x % 10;
        head = new ListNode(x);

    }

    ListNode* ptr = head;

    while (l1 || l2)
    {
        if (l1 && l2)
        {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            x = x % 10;
            ListNode* n = new ListNode (x);

            ptr->next = n;
            ptr = n;
            l1 = l1->next;
            l2 = l2->next;

        }
        else if (l1)
        {
            int x = l1->val + carry;
            carry = x / 10;
            x = x % 10;
            ListNode* n = new ListNode (x);

            ptr->next = n;
            ptr = n;
            l1 = l1->next;
        }
        else {
            int x = l2->val + carry;
            carry = x / 10;
            x = x % 10;
            ListNode* n = new ListNode (x);

            ptr->next = n;
            ptr = n;
            l2 = l2->next;

        }
    }

    if (carry)
    {
        ptr->next = new ListNode(1);
    }

    return head;
}

