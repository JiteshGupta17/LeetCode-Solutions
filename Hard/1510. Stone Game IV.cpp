class Solution {
public:
    
    static const int N = 1e5 + 5;
    int dp[N][2];
    
    bool solve(int n,int turn)
    {
        if(n==0)
        {
            return turn==1;
        }
        
        int &ans = dp[n][turn];
        if(ans != -1) return ans;
            
        if(turn==0)
        {
            // if Alice wins via any move she chooses that path only
            for(int i = 1;i*i<=n;i++)
            {
                bool recAns = solve(n-i*i,turn^1);
                if(recAns) return ans = true;
            }
            
            return ans = false;
        }
        
        for(int i = 1;i*i<=n;i++)
        {
            // if Bob win via any path he choses that only
            bool recAns = solve(n-i*i,turn^1);
            if(!recAns) return ans = false;
        }
        
        return ans = true;

    }
    
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n,0);
        
    }
};
