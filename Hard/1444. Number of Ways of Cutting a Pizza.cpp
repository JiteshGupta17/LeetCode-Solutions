class Solution {
public:

    int dp[52][52][11];
    int n, m;
    const int mod = 1e9 + 7;

    int suffix[52][52];

    int solve(int i, int j, int k)
    {
        if (k == 1)
        {
            // atleast one apple should be there in the remaining pizza
            return suffix[i][j] > 0;
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        // vertical cuts along column
        int res = 0;
        for (int col = j; col < m; col++)
        {
            // means atleast one apple present in the portion to be cut and removed
            if (suffix[i][j] - suffix[i][col + 1] > 0)
            {
                res += solve(i, col + 1, k - 1);
                res %= mod;
            }
        }

        // Horizontal cur along rows
        for (int row = i; row < n; row++)
        {
            if (suffix[i][j] - suffix[row + 1][j] > 0)
            {
                res += solve(row + 1, j, k - 1);
                res %= mod;
            }
        }

        return dp[i][j][k] = res;
    }

    int ways(vector<string>& pizza, int k) {

        n = pizza.size();
        m = pizza[0].length();

        memset(suffix, 0, sizeof suffix);
        memset(dp, -1, sizeof dp);

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                suffix[i][j]  = (pizza[i][j] == 'A') + suffix[i][j + 1];
            }
        }


        for (int j = 0; j < m; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                suffix[i][j] += suffix[i + 1][j];
            }
        }

        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<m;j++)
        //     {
        //         cout<<suffix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return solve(0, 0, k);

    }
};
