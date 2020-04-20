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
    
    TreeNode* buildTree(TreeNode* node,int x)
    {
        if(node==NULL)
        {
           return new TreeNode(x); 
        }
        
        if(node->val > x)
        {
            node->left = buildTree(node->left,x);
        }
        else
            node->right = buildTree(node->right,x);
        
        return node;
        
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i = 1;i<preorder.size();i++)
        {
            buildTree(root,preorder[i]);
        }
        
        return root;
    }
};
