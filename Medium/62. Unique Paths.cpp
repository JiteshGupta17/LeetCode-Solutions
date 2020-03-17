
// Space O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];

    }
};

// Space O(n) beats all solutions in time and space
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[j] +=  dp[j + 1];
            }
        }

        return dp[0];

    }
};
