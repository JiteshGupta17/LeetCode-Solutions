class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq(k);
        int n = nums.size();
        vector<int> ans(n-k+1);
        int idx = 0;
        
        int i = 0;
        for(;i<k;i++)
        {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        for(;i<n;i++)
        {
            // Answere for the i-k to i window
            ans[idx++] = nums[dq.front()];
            
            // Remove elements which are not part of window
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            
            // Remove elements which are not useful
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            
            // Add new element
            dq.push_back(i);
            
        }
        
        ans[idx++] = nums[dq.front()];
        
        return ans;
        
    }
};
