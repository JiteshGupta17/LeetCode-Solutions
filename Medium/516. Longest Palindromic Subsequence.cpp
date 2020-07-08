class Solution {
public:

    int dp[1001][1001];

    int solve(int i,int j,string s)
    {
        if(i>j) return 0;
        if(i==j) return 1;

        int & ans = dp[i][j];
        if(ans != -1) return ans;

        if(s[i]==s[j]) return ans = 2 + solve(i+1,j-1,s);

        return ans =max(solve(i+1,j,s),solve(i,j-1,s));
    }

    int longestPalindromeSubseq(string s) {
        
        // memset(dp,-1,sizeof dp);
        // return solve(0,s.length()-1,s);
        
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int gap = 0;gap<n;gap++)
        {
            for(int i = 0,j = gap;j<n;j++,i++)
            {
                if(gap==0)//i == j
                {
                    dp[i][j] = 1;
                }
                else{
                    if(s[i]==s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                    else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
