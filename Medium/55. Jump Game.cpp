class Solution {
public:
    bool canJump(vector<int>& nums) {
    
        // Greedy
        int n = nums.size();
        int idx = n-1;
        
        while(idx)
        {
            int cur = -1;
    //Finding the first element to the left of cur_idx through which we can reach here
            for(int i = idx-1;i>=0;i--)
            {
                if(i + nums[i] >= idx)
                {
                    cur = i;
                    break;
                }
            }
            
            if(cur==-1) return false; // if no element found on left through which we can reach here
            idx = cur;
        }
        
        return true;
        
        // DP - TLE
        // int n = nums.size();
        // vector<bool> dp(n,false);
        // dp[n-1] = true;
        
        // for(int i = n-2;i>=0;i--)
        // {
        //   for(int j = 1;j<=nums[i];j++)
        //    {
        //        dp[i] = dp[i] || dp[i+j];
        //        if(dp[i]) break;
        //    }
        // }
        
        // return dp[0];
        
    }
};
