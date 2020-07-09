
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        
        long long ans = 0;

        
        while(!q.empty())
        {
            int cur_size = q.size();
            unsigned long long l  = q.front().second;
            unsigned long long r = q.front().second;
            
            for(int i = 0;i<cur_size;i++)
            {
                auto cur = q.front();
                q.pop();
                
                TreeNode* node = cur.first;
                unsigned long long idx = cur.second;
                
                r = idx;
                
                if(node->left)
                {
                    q.push({node->left,2*idx});
                }
                
                if(node->right)
                {
                    q.push({node->right,2*idx + 1});
                }
            }
            
            long long cur_ans = r-l+1;
            ans = max(ans,cur_ans);
        }
        
        return ans;
    }
};
