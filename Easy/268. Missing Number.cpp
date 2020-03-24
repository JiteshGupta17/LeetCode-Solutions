class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // We can assume that each number will occur twice by considering the indices also as numbers
        // and by xoring two same numbers result into zero so only that number will be left which will not be present
        
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            ans ^= i+1;
            ans ^= nums[i];
        }
        
        return ans;
    }
};
