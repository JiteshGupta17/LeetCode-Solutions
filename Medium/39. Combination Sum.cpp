
// Recursive
class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& candidates, int target, vector<int> cur)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }

        if (idx == n) return;

        // if(target>=candidates[idx])
        // {
        //     cur.push_back(candidates[idx]);
        //     solve(idx,candidates,target -candidates[idx] ,cur);
        //     cur.pop_back();
        // }

        // solve(idx+1,candidates,target ,cur);

        for (int i = idx; i < n; i++)
        {
            if (target - candidates[i] >= 0)
            {
                cur.push_back(candidates[i]);
                solve(i, candidates, target - candidates[i], cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        solve(0, candidates, target, {});
        return ans;
    }
};

/////////////////////////////////////////////////////////////////////////////////////

// Iterative DP
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> dp[target + 1];
        dp[0] = {{}}; // Initialising a empty vector

        for (int coin : candidates)
        {
            for (int amount = 1; amount <= target; amount++)
            {
                if (amount - coin >= 0)
                {
                    for (auto vec : dp[amount - coin])
                    {
                        vec.push_back(coin);
                        dp[amount].push_back(vec);
                    }
                }
            }
        }

        return dp[target];
    }
};