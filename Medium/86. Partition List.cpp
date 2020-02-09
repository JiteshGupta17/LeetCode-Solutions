
// O(n) Time and O(1) Space as we have not made new nodes just reordering the given ones
ListNode* partition(ListNode* head, int x) {
    
    ListNode* Small = new ListNode(-1);
    ListNode* start1 = Small;

    ListNode* Large = new ListNode(-1);
    ListNode* start2 = Large;

    while (head)
    {
        if (head->val < x)
        {
            Small->next = head;
            Small = head;
        }
        else {
            Large->next = head;
            Large = head;
        }
        head = head->next;
    }

    Large->next = NULL;
    Small->next = start2->next;

    return start1->next;
}
