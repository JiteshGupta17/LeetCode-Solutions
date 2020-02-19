class Solution {
public:
    
    vector<int> ans;
    void PreOrder(Node*root)
    {
        if(root==NULL) return ;
        
        ans.push_back(root->val);
        
        for(auto child : root->children)
        {
            PreOrder(child);
        }
    }
    vector<int> preorder(Node* root) {
        
        ans = {};
        
        PreOrder(root);
        
        return ans;
        
    }
};
