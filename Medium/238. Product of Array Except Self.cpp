class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,1);
        int prod_left = 1;
        
        for(int i = 0;i<n;i++)
        {
            ans[i] *= prod_left;
            prod_left *= nums[i];
        }
        
        int prod_right = 1;
        for(int i = n-1;i>=0;i--)
        {
            ans[i] *= prod_right;
            prod_right *= nums[i];
        }
        
        return ans;
    }
};
