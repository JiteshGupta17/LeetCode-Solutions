class Solution {
public:
    int mod = 1e9 + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        
        vector<int> cnt(1e6+1), power(1e6+1),freq(1e6 + 1);
        
        for(int ele : nums)
        {
            freq[ele]++;
            cnt[ele]++;
        }
        
        power[0] = 1;
        for(int i = 1;i<=1e6;i++)
        {
            freq[i] += freq[i-1];
            power[i] = 2*power[i-1]%mod;
        }
        
        long long ans = 0;
        for(int i = 1;i<=target/2;i++)
        {
            if(cnt[i]==0) continue;
            
            long long rem = target - i;
            
            int btw = freq[rem] - freq[i];
            // cout<<i<<" "<<btw<<endl;
            
            long long x = power[cnt[i]] - 1;
            long long y = power[btw];
            
            long long cur = (x*y)%mod;
            // cout<<cur<<endl;
            ans += cur;
            ans %= mod;
            
        }
        
        return ans;
    }
};