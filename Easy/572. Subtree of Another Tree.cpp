class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(t==NULL) return true;
        
        if(s==NULL) return false;
        
        return isSame(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        
    }
    
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s==NULL) return t==NULL;
        if(t==NULL) return s==NULL;
        
        return s->val==t->val && isSame(s->left,t->left) && isSame(s->right,t->right);
    }
};
