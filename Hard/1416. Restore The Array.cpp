
class Solution {
public:
    const int mod = 1e9 + 7;
    
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i]=='0') continue;
            else{
                
                long long cur = 0;
                for(int j = i;j<=n-1;j++)
                {
                    cur = cur*10;
                    cur += s[j]-'0';
                    
                    if(cur <=k)
                    {
                        dp[i] += dp[j+1];
                        dp[i] %= mod;
                    }
                    else break;
                }  
            }
        }
        
        // for(int ele : dp) cout<<ele<<" ";
        
        return dp[0];
        
    }
};
