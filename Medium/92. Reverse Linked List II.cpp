
// Main Function
ListNode* reverseBetween(ListNode* head, int m, int n) {

    ListNode* Dummy = new ListNode(0);
    Dummy->next = head;

    ListNode* nth = Dummy; // will stop at n

    ListNode* mth = Dummy; // will stop at m-1

    while (n)
    {
        nth = nth->next;

        if (m - 1 == n)
        {
            mth = mth->next;
            m--;
        }
        n--;
    }

    ListNode* after_n = nth->next;
    nth->next = NULL;

    mth->next = ReverseList(mth->next);

    ListNode* cur = Dummy;
    while (cur->next) cur = cur->next;

    cur->next = after_n;

    return Dummy->next;

}

ListNode* ReverseList(ListNode* head) {
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
