class Solution {
public:
    const int n = 9;
    bool rows[10][10];
    bool cols[10][10];
    bool blocks[10][10];

    bool solve(int row, int col, vector<vector<char>>& board)
    {
        if (row == n)
        {
            return true;
        }

        if (col == n)
        {
            return solve(row + 1, 0, board);
        }

        if (board[row][col] != '.') return solve(row, col + 1, board);

        bool res = false;
        for (int i = 1; i <= 9; i++)
        {
            int id = 3 * (row / 3) + col / 3;

            if (!rows[row][i] && !cols[col][i] && !blocks[id][i])
            {
                rows[row][i] = cols[col][i] = blocks[id][i] = 1;
                board[row][col] = char(i + '0');

                bool res = solve(row, col + 1, board);
                if (res) return true;

                rows[row][i] = cols[col][i] = blocks[id][i] = 0;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.') continue;

                int cur = board[i][j] - '0';
                rows[i][cur] = 1;
                cols[j][cur] = 1;

                int id = 3 * (i / 3) + j / 3;

                blocks[id][cur] = 1;
            }
        }

        solve(0, 0, board);
    }
};