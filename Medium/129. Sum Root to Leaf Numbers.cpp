class Solution {
public:

    int ans;

    void rootToLeaf(TreeNode* root, int curSum)
    {
        if (!root) return;

        // leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            ans += 10 * curSum + root->val;
            return ;
        }

        rootToLeaf(root->left, 10 * curSum + root->val);
        rootToLeaf(root->right, 10 * curSum + root->val);
    }

    int sumNumbers(TreeNode* root) {
        ans = 0;

        rootToLeaf(root, 0);

        return ans;

    }
};
