
// Recursive
bool isSameTree(TreeNode* p, TreeNode* q) {

    if (p == NULL) return q == NULL;
    if (q == NULL) return p == NULL;

    bool res = false;

    res = (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    return res;
}

// Iterative
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Main idea is to compare each node while adding in stack and at last whther the no of nodes were same in both or not
    // MAintaining a stack for each tree
    stack<TreeNode*> stack_p;
    stack<TreeNode*> stack_q;

    if (p)   stack_p.push(p);
    if (q)   stack_q.push(q);

    while (!stack_p.empty() && !stack_q.empty()) {
        TreeNode* cur_p = stack_p.top();
        TreeNode* cur_q = stack_q.top();

        stack_p.pop();
        stack_q.pop();

        if (cur_p->val != cur_q->val) return false;

        if (cur_p->left) stack_p.push(cur_p->left);
        if (cur_q->left) stack_q.push(cur_q->left);
        if (stack_p.size() != stack_q.size())    return false;

        if (cur_p->right) stack_p.push(cur_p->right);
        if (cur_q->right) stack_q.push(cur_q->right);
        if (stack_p.size() != stack_q.size())    return false;
    }

    return stack_p.size() == stack_q.size();
}
