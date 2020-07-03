class Solution {
public:
    vector<bool> col, diag1, diag2;
    int nn;

    int solve(int row)
    {
        if (row == nn)
        {
            return 1;
        }

        int ans = 0;

        for (int c = 0; c < nn; c++)
        {
            if (!col[c] && !diag1[row + c] && !diag2[row - c + nn])
            {
                col[c] = 1;
                diag1[row + c] = 1;
                diag2[row - c + nn] = 1;

                ans += solve(row + 1);

                col[c] = 0;
                diag1[row + c] = 0;
                diag2[row - c + nn] = 0;

            }
        }

        return ans;
    }

    int totalNQueens(int n) {

        nn = n;
        col.resize(n);
        diag1.resize(2 * n + 1);
        diag2.resize(2 * n + 1);

        return solve(0);

    }
};