class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Now the problem becomes Difference of any two pairs is equal to k
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        mp[0]++;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            
            // We just have to find whether sum-k has occured befor or not
            if(mp.count(sum-k))
            {
                ans += mp[sum-k];
            }
            
            mp[sum]++;
           
        }
        
        return ans;
        
    }
};
