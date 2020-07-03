class Solution {
public:

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        bool board[8][8] = {};
        for (auto vec : queens)
        {
            board[vec[0]][vec[1]] = 1;
        }

        vector<vector<int>> ans;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0) continue;

                int x = king[0];
                int y = king[1];

                while (x >= 0 && x < 8 && y >= 0 && y < 8)
                {
                    if (board[x][y])
                    {
                        ans.push_back({x, y});
                        break;
                    }
                    x += i;
                    y += j;

                }
            }
        }

        return ans;
    }
};