// DFS - Recursion
int maxDepth(TreeNode* root) {

    if (root == NULL) return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;

}

// BFS - Iterative
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        ans ++;
        int n  = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur -> left != NULL)
                q.push(cur -> left);
            if (cur -> right != NULL)
                q.push(cur -> right);
        }
    }

    return ans;
}
