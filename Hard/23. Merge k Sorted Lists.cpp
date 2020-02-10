
/*(Best) Method - 1 Using Priority Queue 28ms*/
struct Compare {
    bool operator()(const ListNode* l1, const ListNode* l2)
    {
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<ListNode*, vector<ListNode*>, Compare > pq;

    for (int i = 0; i < lists.size(); i++)
    {

        while (lists[i])
        {
            ListNode* cur = lists[i];
            pq.push(cur);
            lists[i] = lists[i]->next;
        }
    }

    ListNode* Dummy = new ListNode(0);
    ListNode* cur = Dummy;

    while (!pq.empty())
    {
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
    }

    cur->next = NULL;
    return Dummy->next;
}

// ===============================================================================

/*Method 2 - find the list with minimum head and add it to the resultant list*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* Dummy = new ListNode(0);
    ListNode* cur = Dummy;

    int c = -1;
    int min_val = INT_MAX;
    for (int i = 0; i < lists.size(); i++)
    {

        if (lists[i] && lists[i]->val < min_val)
        {
            min_val = lists[i]->val;
            c = i;
        }
    }

    if (c == -1)
        return Dummy->next;

    cur->next = lists[c];
    lists[c] = lists[c]->next;
    cur = cur->next;

    cur->next = mergeKLists(lists);

    return Dummy->next;

}

// ===============================================================================

/*Method 3 is to keep on merging 2 lists, removing them and pushing their merged form
till only 1 list remains*/

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists[0];

    while (lists.size() > 1)
    {
        ListNode* ans = mergeTwoLists(lists[0], lists[1]);
        lists.erase(lists.begin());
        lists.erase(lists.begin());

        lists.push_back(ans);
    }

    return lists[0];


}

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

