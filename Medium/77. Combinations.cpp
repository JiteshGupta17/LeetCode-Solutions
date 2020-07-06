class Solution {
public:
    vector<vector<int>> ans;

    void solve(int cur, int n, int k, vector<int> aa)
    {
        if (k == 0) {
            ans.push_back(aa);
            return;
        }

        if (cur == n + 1) return;

        for (int i = cur; n - i + 1 >= k; i++)
        {
            aa.push_back(i);
            solve(i + 1, n, k - 1, aa);
            aa.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        solve(1, n, k, {});
        return ans;
    }
};