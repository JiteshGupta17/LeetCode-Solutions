class Solution {
public:
    
    // Always add the right element if present of cur element 
    // Also if cur element is present in zero column then add its below element also
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n==0)return vector<int>();
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vector<int> ans;
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            ans.push_back(nums[p.first][p.second]);
            
            if(p.second==0 && p.first + 1 < n)
            {
                q.push({p.first+1,p.second});
            }
            
            if(p.second + 1 < nums[p.first].size())
            {
                q.push({p.first,p.second+1});
            }
            
        }
        
        return ans;
        
    }
};
