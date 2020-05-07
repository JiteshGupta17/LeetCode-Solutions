class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        // current and its parent
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, root});

        while (!q.empty())
        {
            auto cur = q.front();

            int cur_size = q.size();

            bool f = false;
            TreeNode* parent;

            for (int i = 0; i < cur_size; i++)
            {
                TreeNode* node = cur.first;
                TreeNode* its_parent = cur.second;

                // cout<<node->val<<" ";

                if (node->val == x || node->val == y)
                {
                    if (f) {
                        if (its_parent != parent) return true;
                        else return false;
                    }

                    f = true;
                    parent = its_parent;
                }

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});

                q.pop();

                if (!q.empty())  cur = q.front();

            }

            // cout<<endl;

            if (f) return false;
        }

        return false;

    }
};
