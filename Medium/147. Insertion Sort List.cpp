ListNode* insertionSortList(ListNode* head) {

    // Sorted list
    ListNode* Dummy = new ListNode(0);

    while (head)
    {
        ListNode* P_prev = Dummy;
        ListNode* nxt = head->next;

        bool added = false;

        while (P_prev->next)
        {
            if (P_prev->next->val >= head->val)
            {
                ListNode* afterPrev = P_prev->next;
                P_prev->next = head;
                head->next = afterPrev;

                added = true;
                break;
            }

            P_prev = P_prev->next;
        }

        // if not added then must be added at End of new list
        if (!added)
        {
            P_prev->next = head;
            head->next = NULL;
        }

        head = nxt;
    }

    return Dummy->next;
}
