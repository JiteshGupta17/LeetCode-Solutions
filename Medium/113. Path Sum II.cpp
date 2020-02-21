class Solution {
public:
    
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int sum,vector<int>& cur)
    {   if(root==NULL) return;  
     
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==root->val)
            {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return ;
        }
        
        cur.push_back(root->val);
        helper(root->left,sum-root->val,cur);
        helper(root->right,sum-root->val,cur);
        cur.pop_back();
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;
        helper(root,sum,cur);
        return ans;
    }
};
