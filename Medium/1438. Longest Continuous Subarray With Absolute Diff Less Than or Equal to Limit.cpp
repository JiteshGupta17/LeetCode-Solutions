class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        int r = 1;
        multiset<int> s;
        s.insert(nums[0]);
        int ans = 1;
        
        for(int l = 0;l<n;l++)
        {
            if(s.empty()) {
                s.insert(nums[l]);
                r = l+1;
            }
            int least = *s.begin();
            int most = *s.rbegin();
            
            while(r<n && abs(nums[r] - least) <=limit && abs(nums[r]-most) <=limit)
            {
                s.insert(nums[r]);
                least = min(least,nums[r]);
                most = max(most,nums[r]);
                r++;
            }
            
            ans = max(ans,(int)s.size());
            s.erase(s.find(nums[l]));
            
        }
        
        return ans;
        
        
    }
};
