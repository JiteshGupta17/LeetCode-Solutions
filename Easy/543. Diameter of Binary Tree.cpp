class Solution {
public:
    int ans;
    
    int depth(TreeNode*root)
    {
        if(root==NULL) return 0;
        
        int l = depth(root->left); // Height of left subtree
        int r = depth(root->right); // Height of right subtree
        
        ans = max(ans,l+r+1); // max diameter in terms of node including this node
        
        return max(l,r) + 1; // max Height
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        ans = 1;
        depth(root);
        
        return ans-1;
        
    }
};
