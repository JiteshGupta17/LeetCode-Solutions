/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_d;
    
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        
        int l = 1 + helper(root->left);
        int r = 1 + helper(root->right);
        
        max_d = max(max_d,l+r-1);
        // cout<<root->val<<" "<<l<<" "<<r<<endl;
        
        return max(l,r);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        max_d = 0;
        max_d = max(max_d,helper(root));
         return max_d > 0 ? max_d - 1 : 0;
    }
};
