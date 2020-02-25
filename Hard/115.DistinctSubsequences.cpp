#include <bits/stdc++.h>
using namespace std;

int numDistinct_recur(string s, string t, int i, int j)
{
    if (j == t.length()) return 1;

    if (i == s.length()) return 0;

    int count = 0;
    if (s[i] == t[j])
    {
        count += numDistinct_recur(s, t, i + 1, j + 1); // Might be one of the occurance
        count += numDistinct_recur(s, t, i + 1, j); // Might be another occurance in rem string
    }
    else count = numDistinct_recur(s, t, i + 1, j); // Look for other occurances

    return count;
}

int numDistinct(string s, string t) {

    int n = s.length();
    int m = t.length();

    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n) {
                dp[i][j] = 0; // No string can be suseq of empty string s
                if (j == m) dp[i][j] = 1;
                continue;
            }
            if (j == m) {
                dp[i][j] = 1; //Empty string t is subseq
                continue;
            }

            if (s[i] == t[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
            else dp[i][j] = dp[i + 1][j];
        }
    }

    return dp[0][0];

}

int main()
{
    cout << numDistinct_recur("rabbbit", "rabbit", 0, 0);
    cout << numDistinct("rabbbit", "rabbit");
    return 0;
}