void flatten(TreeNode* &root) {

    if (!root) return ;

    // Storing the adresses of left and right
    TreeNode* lt = root->left;
    TreeNode* rt = root->right;

    // Flatten left and right
    flatten(lt);
    flatten(rt);

    // Break the left by NULLifying it and make the flatten left as new right
    root->left = NULL;
    root->right = lt;

    // Final step is to find the end of flatten tree with root and flatten left and at the end join it with flatten right
    TreeNode* cur = root;

    while (cur->right)
    {
        cur = cur->right;
    }

    cur->right = rt;


}
