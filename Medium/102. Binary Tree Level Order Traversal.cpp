
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> level;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        level.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);

        if (q.front() == NULL)
        {
            ans.push_back(level);
            level.clear();
            q.pop();

            if (!q.empty()) q.push(NULL);
        }
    }

    return ans;

}
