class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int n = s.length();
        for (string word : wordDict)
        {
            set.insert(word);
        }
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            string combine = "";
            int len = n - i;
            for (int j = 0; j < len; j++)
            {
                combine += s[i + j];
                if (dp[i + j + 1] && set.count(combine))
                {
                    dp[i] = true;
                    break;
                }
            }
            // cout<<dp[i]<<" ";
        }
        return dp[0];
    }
};
