class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        
        int prev_pos = -1;
        
        // Check all 1's position and its previous 1's position
        for(int i = 0;i<n;i++)
        {
            if(prev_pos == -1 && nums[i]==1)
            {
                prev_pos = i;
                continue;
            }
            
            if(nums[i]==1)
            {
                if(prev_pos >= i-k ) return false;
                prev_pos = i;
            }
        }
        
        return true;
    }
};
