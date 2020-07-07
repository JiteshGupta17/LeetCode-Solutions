// Recursive
class Solution {
public:

    vector<vector<int>> ans;

    void solve(int cur, int target, int k, vector<int> path)
    {
        if (k == 0 && target == 0)
        {
            ans.push_back(path);
            return;
        }

        for (int i = cur; 9 - cur + 1 >= k && target - i >= 0 && i <= 9; i++)
        {

            path.push_back(i);
            solve(i + 1, target - i, k - 1, path);
            path.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        solve(1, n, k, {});
        return ans;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////

// Iterative
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> dp[n + 1];
        dp[0] = {{}};

        for (int i = 1; i <= 9; i++)
        {
            for (int amount = n; amount >= 1; amount--)
            {
                if (amount - i >= 0)
                {
                    for (auto vec : dp[amount - i])
                    {
                        if ( (amount != n && vec.size() < k - 1) || (amount == n && vec.size() == k - 1))
                        {
                            vec.push_back(i);
                            dp[amount].push_back(vec);
                        }
                    }
                }
                else break;
            }
        }

        return dp[n];
    }
};