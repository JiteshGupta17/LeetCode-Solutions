
// Recursive ->
void inorder_recur(TreeNode* root, vector<int> &ans)
{
    if (root == NULL) return ;

    inorder_recur(root->left, ans);
    ans.push_back(root->val);
    inorder_recur(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    // left root right
    vector<int> ans;

    inorder_recur(root, ans);
    return ans;
}


// Iterative ->
// =====================================================================================

vector<int> inorderTraversal(TreeNode* root) {
    // left root right
    vector<int> ans;
    stack<TreeNode*> s;
    auto cur = root;

    while (cur != NULL || !s.empty())
    {
        while (cur) // here we never come to a node which is been visited
        {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        ans.push_back(cur->val);
        s.pop();

        cur = cur->right; // Main step which prevenst the use of hashmap
    }

    return ans;
}

// =====================================================================================

// HashMap + stack
vector<int> inorderTraversal(TreeNode* root) {
    // left root right
    vector<int> ans;
    if (root == NULL) return ans;

    unordered_map<TreeNode*, int> mp;
    stack<TreeNode*> s;
    mp[root] = 1;
    s.push(root);



    while (!s.empty())
    {
        auto cur = s.top();

        while (cur->left && (mp.find(cur->left) == mp.end()))
        {
            mp[cur->left] = 1;
            s.push(cur->left);
            cur = cur->left;
        }

        cur = s.top();
        ans.push_back(cur->val);
        s.pop();

        if (cur->right) s.push(cur->right);
    }

    return ans;
}
