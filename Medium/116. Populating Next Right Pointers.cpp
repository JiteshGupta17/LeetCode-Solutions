/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        // Simple use of level order

        if (!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            int n = q.size();

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);

            for (int i = 0; i < n; i++)
            {
                cur->next = q.front();
                cur = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                q.pop();
            }

            cur->next = NULL;
        }

        return root;

    }
};
