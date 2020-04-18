class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        
        int m = grid[0].size();
        
        vector<int> dp(m+1);
        
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(i==n-1)
                {
                    if(j==m-1) dp[j] = grid[i][j];
                    else dp[j] = dp[j+1] + grid[i][j];
                }
                else{
                    if(j==m-1) dp[j] = grid[i][j] + dp[j];
                    else dp[j] = grid[i][j] + min(dp[j],dp[j+1]);
                }
            }
        }
        
        return dp[0];
    }
};
