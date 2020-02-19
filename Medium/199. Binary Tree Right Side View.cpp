vector<int> rightSideView(TreeNode* root) {

    // Level order and push right then left
    // and at each level print the first node data in queue of that level
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop();
        int n = q.size();

        ans.push_back(cur->val);

        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);

        for (int i = 0; i < n; i++)
        {
            cur = q.front();
            if (cur->right) q.push(cur->right);
            if (cur->left) q.push(cur->left);
            q.pop();
        }

    }

    return ans;
}
