
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

        // More time
        // if(target>=candidates[idx])
        // {
        //     cur.push_back(candidates[idx]);
        //     solve(idx,candidates,target -candidates[idx] ,cur);
        //     cur.pop_back();
        // }

        // solve(idx+1,candidates,target ,cur);

        // Less time
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

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        set<multiset<int>> res[target + 1];

        for (int i = 0; i <= target; i++)
        {
            for (int coin : candidates)
            {
                if (i - coin >= 0)
                {
                    if (i - coin == 0)
                    {
                        multiset<int> v = {coin};
                        res[i].insert(v);
                    }
                    else if (!res[i - coin].empty())
                    {
                        for (auto vec : res[i - coin])
                        {
                            vec.insert(coin);
                            res[i].insert(vec);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto s : res[target])
        {
            vector<int> v(s.begin(), s.end());
            ans.push_back(v);
        }

        return ans;
    }
};