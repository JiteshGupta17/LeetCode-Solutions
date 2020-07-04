class Solution {
public:
    int dp[1001];
    int solve(int cur)
    {
        if (cur <= 1000 && dp[cur] != -1) return dp[cur];
        if (cur == 1) return 0;
        if (cur & 1)
        {
            int x = 3 * cur + 1;
            int ans = 1 + solve(x);
            if (cur <= 1000) dp[cur] = ans;
            return ans;
        }

        int ans = 1 + solve(cur / 2);
        if (cur <= 1000) dp[cur] = ans;
        return ans;
    }

    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof dp);

        vector<pair<int, int>> v;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 1; i <= hi; i++)
        {
            if (dp[i] == -1)
                dp[i] = solve(i);
            if (i >= lo && i <= hi) v.push_back({dp[i], i});
        }

        sort(v.begin(), v.end());
        return v[k - 1].second;

    }
};