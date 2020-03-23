class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int count = 0;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j] = min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1])) + 1;
                    
                    count += dp[i][j];
                    
                }
                
            }
        }
        
        // for(auto vec : dp)
        // {
        //     for(int ele : vec) cout<<ele<<" ";
        //     cout<<endl;
        // }
        
        
        return count;
        
    }
};
