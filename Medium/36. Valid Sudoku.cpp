class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Checking each row
        for (int i = 0; i < 9; i++)
        {
            vector<bool> v(10);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (v[cur]) return false;
                v[cur] = 1;
            }
        }

        // Checking each col
        for (int j = 0; j < 9; j++)
        {
            vector<bool> v(10);
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (v[cur]) return false;
                v[cur] = 1;
            }
        }

        vector<vector<bool>> blocks(10, vector<bool>(10));
        // Checking each block
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                // cout<<3*(i/3) + j/3<<endl;
                int block_id = 3 * (i / 3) + j / 3;
                if (blocks[block_id][cur]) return false;
                blocks[block_id][cur] = true;
            }
        }

        return true;
    }
};