class Solution {
public:

    // Similiar to LCS , min instead to max
    int dp[1005][1005];

    int solve(int i, int j, string s, string t)
    {
        if (i == s.length()) return dp[i][j] = t.length() - j;
        if (j == t.length()) return dp[i][j] = s.length() - i;

        int &ans = dp[i][j];
        if (ans != -1) return ans;

        if (s[i] == t[j])
        {
            return ans = 1 + solve(i + 1, j + 1, s, t);
        }

        ans = 1 + solve(i + 1, j, s, t); // included char of s
        ans = min(ans, 1 + solve(i, j + 1, s, t)); // included char of t

        return ans;
    }

    string shortestCommonSupersequence(string s, string t) {

        // Recursive
        // memset(dp,-1,sizeof dp);
        // solve(0,0,s,t)<<endl;

        int n = s.length();
        int m = t.length();

        for (int i = n; i >= 0; i--)
        {
            for (int j = m; j >= 0; j--)
            {
                if (i == n) dp[i][j] = m - j;
                else if (j == m) dp[i][j] = n - i;
                else if (s[i] == t[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        string ans = "";
        int i = 0, j = 0;

        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j]) {
                ans += s[i];
                i++; j++;
            }
            else if (dp[i + 1][j] < dp[i][j + 1]) {
                ans += s[i];
                i++;
            }
            else {
                ans += t[j];
                j++;
            }

        }

        if (i == s.length()) ans += t.substr(j);
        else if (j == t.length()) ans += s.substr(i);

        return ans;
    }
};
