class Solution {
public:
    
    
    int helper(TreeNode* root,int max_val)
    {
        if(root==NULL) return 0;
        int add = 0;
        if(root->val >= max_val) add++;
        return add + helper(root->left,max(max_val,root->val)) + helper(root->right,max(max_val,root->val));
        
    }
    
    int goodNodes(TreeNode* root) {
        
        return helper(root,root->val) ;
        
        
    }
};
