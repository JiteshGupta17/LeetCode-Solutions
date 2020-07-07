class Solution {
public:
    int n, m;
    int ans = 0;
    vector<pair<int, int>> direc = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

    void solve(int i, int j, vector<vector<int>>& grid, int gold)
    {
        ans = max(ans, gold);
        for (auto d : direc)
        {
            int x = i + d.first;
            int y = j + d.second;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y])
            {
                int temp = grid[x][y];
                grid[x][y] = 0;
                solve(x, y, grid, gold + temp);
                grid[x][y] = temp;
            }
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int temp = grid[i][j];
                    grid[i][j] = 0;
                    solve(i, j, grid, temp);
                    grid[i][j] = temp;
                }

            }
        }

        return ans;
    }
};
