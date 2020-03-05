    int singleNumber(vector<int>& nums) {
        
        // On the fact that xor of two same numbers is zero and zero xor any nymber is the number itself
        int ans = 0;
        
        for(int ele : nums)
        {
            ans = ans^ele;
        }
        
        return ans;
        
    }
