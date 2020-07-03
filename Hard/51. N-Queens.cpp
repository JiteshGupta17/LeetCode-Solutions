class Solution {
public:

    vector<bool> col, diag1, diag2;
    int nn;

    vector<vector<string>> ans;

    void solve(int row, vector<string> &cur)
    {
        if (row == nn)
        {
            ans.push_back(cur);
            return;
        }

        for (int c = 0; c < nn; c++)
        {
            if (!col[c] && !diag1[row + c] && !diag2[row - c + nn])
            {
                col[c] = 1;
                diag1[row + c] = 1;
                diag2[row - c + nn] = 1;
                cur[row][c] = 'Q';

                solve(row + 1, cur);

                col[c] = 0;
                diag1[row + c] = 0;
                diag2[row - c + nn] = 0;
                cur[row][c] = '.';

            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {

        nn = n;
        col.resize(n);
        diag1.resize(2 * n + 1);
        diag2.resize(2 * n + 1);

        vector<string> cur(n);
        string s = string(n, '.');

        for (auto & x : cur) x = s;

        int row = 0;
        solve(row, cur);

        return ans;


    }
};