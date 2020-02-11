vector<int> nextLargerNodes(ListNode* h) {
    vector<int> res, stack;

    while (h)
    {
        res.push_back(h->val);
        h = h->next;
    }

    for (int i = res.size() - 1; i >= 0; --i) {
        int val = res[i];

        while (!stack.empty() && stack.back() <= res[i])
            stack.pop_back();

        res[i] = stack.empty() ? 0 : stack.back();
        stack.push_back(val);
    }
    return res;
}
