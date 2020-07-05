class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        
        for(int i = 0;i<n;i++) dp[i][i] = 0;
        
        for(auto e : edges)
        {
            dp[e[0]][e[1]] = e[2];
            dp[e[1]][e[0]] = e[2];
        }
        
        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int mini = n+1;
        int idx = -1;
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            for(int j = 0;j<n;j++)
            {
                if(j==i) continue;
                if(dp[i][j] <=k) cnt++;
            }
            if(mini >= cnt)
            {
                mini = cnt;
                idx = i;
            }
            
        }
        
        return idx;
    }
};
