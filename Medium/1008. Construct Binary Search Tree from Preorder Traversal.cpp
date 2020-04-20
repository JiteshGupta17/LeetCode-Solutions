// Recursive
class Solution {
public:

    TreeNode* buildTree(TreeNode* node, int x)
    {
        if (node == NULL)
        {
            return new TreeNode(x);
        }

        if (node->val > x)
        {
            node->left = buildTree(node->left, x);
        }
        else
            node->right = buildTree(node->right, x);

        return node;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++)
        {
            buildTree(root, preorder[i]);
        }

        return root;
    }
};

// Iterative
class Solution {
public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++)
        {
            int x = preorder[i];
            TreeNode* node = root;

            while (true)
            {
                if (node->val > x)
                {
                    if (!node->left) {
                        node->left = new TreeNode(x);
                        break;
                    }
                    else node = node->left;
                }
                else {
                    if (!node->right) {
                        node->right = new TreeNode(x);
                        break;
                    }
                    else node = node->right;
                }
            }
        }

        return root;
    }
};
