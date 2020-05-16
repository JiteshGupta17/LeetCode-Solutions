class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {

        vector<string> dp(target + 1, "0");
        dp[0] = "";

        for (int i = 0; i < 9; i++)
        {
            for (int t = 1; t <= target; t++)
            {
                if (t - cost[i] >= 0 && dp[t - cost[i]] != "0")
                {
                    string cur = (char)(i + 1 + '0') + dp[t - cost[i]];

                    if (dp[t].length() != cur.length()) {

                        if (dp[t].length() < cur.length())
                            dp[t] = cur;
                    }

                    else {

                        if (dp[t] < cur)
                            dp[t] = cur;
                    }

                }
            }

        }

        return dp[target];
    }
};
