class Solution {
public:
    
    int dp[42][42][1610];
    int n,m;
    int ans = INT_MAX;
    
    vector<pair<int,int>> direc = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int helper(int i,int j, int k,vector<vector<int>>& grid,vector<vector<bool>> &visited){
        
        if(i==n-1 && j==m-1) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans = 2000;
        
        for(auto d : direc)
        {
            int x = i + d.first;
            int y = j + d.second;
            
            if(x >= 0 && x < n && y >=0 && y < m && !visited[x][y])
            {
                visited[x][y] = true;
                
                if(grid[x][y]==1)
                {
                    if(k>0)
                    ans = min(ans, 1 + helper(x,y,k-1,grid,visited));
                }
                else{
                    ans = min(ans,1 + helper(x,y,k,grid,visited));
                }
                
                visited[x][y] = false;
            }
        }
        
        return dp[i][j][k] = ans;
        
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[0][0] = true;
        memset(dp,-1,sizeof dp);
        
        int ans = helper(0,0,k,grid,visited);
        if(ans==2000) return -1;
        
        return ans;
        
    }
};
