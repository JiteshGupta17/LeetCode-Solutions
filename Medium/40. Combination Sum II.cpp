class Solution {
public:

    vector<vector<int>> ans;
    int n;

    void solve(int idx, vector<int>& candidates, int target, vector<int> cur)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }

        if (idx == n) return;

        for (int i = idx; i < n; i++)
        {
            // 1st differ
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            if (target - candidates[i] >= 0)
            {
                cur.push_back(candidates[i]);

                // 2nd differ call from i+1
                solve(i + 1, candidates, target - candidates[i], cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, {});
        return ans;
    }
};