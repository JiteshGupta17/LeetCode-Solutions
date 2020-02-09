ListNode* merge(ListNode* l1, ListNode* l2)
{
    ListNode *ans = new ListNode(0);
    ListNode* prev = ans;


    while (l1 && l2) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    if (l1)
        prev->next = l1;

    if (l2)
        prev->next = l2;

    return ans->next;
}



ListNode* sortList(ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* second = slow->next;
    slow->next = NULL;

    ListNode* first = sortList(head);
    second = sortList(second);

    ListNode* ans = merge(first, second);

    return ans;

}
