// Method 1 - O(logn)
class Solution {
public:
    int integerReplacement(int N) {
        int ans = 0;
        
        long long n = N;
        while(n!=1)
        {
            if(n==3){
                ans += 2;
                return ans;
            }

            if(n&1)
            {
                if((n+1)%4==0)
                {
                    n = n+1;
                }
                else n = n-1;
            }
            else n = n/2;
            
            ans++;
        }
        
        return ans;
    }
};

// Method 2 - O(n) wont pass
class Solution {
public:
    int integerReplacement(int n) {
        
        vector<int> dp(n+1,0);
        
        for(int i = 2;i<=n;i++)
        {
            if(i&1)
            {
                dp[i] = 1 + min(dp[(i-1)/2] + 1, dp[(i+1)/2] + 1);
            }
            else dp[i] = 1 + dp[i/2];
        }
        
        return dp[n];
    }
};
