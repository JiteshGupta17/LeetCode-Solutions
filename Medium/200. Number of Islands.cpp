
// DFS
class Solution {
public:
	int n, m;
	vector<pair<int, int>> direc = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
	void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
	{
		for (auto& p : direc)
		{
			int x = i + p.first;
			int y = j + p.second;

			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				if (grid[x][y] == '1' && !visited[x][y])
				{
					visited[x][y] = true;
					dfs(x, y, grid, visited);
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		n = grid.size();
		if (!n) return 0;

		m = grid[0].size();

		int cnt = 0;
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					cnt++;
					visited[i][j] = true;
					dfs(i, j, grid, visited);
				}
			}
		}
		return cnt;
	}
};

// ================================================================================

// BFS
class Solution {
public:
	int n, m;
	vector<pair<int, int>> direc = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
	void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
	{
		queue<pair<int, int>> q;
		q.push({i, j});

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (auto& p : direc)
			{
				int x = cur.first + p.first;
				int y = cur.second + p.second;

				if (x >= 0 && x < n && y >= 0 && y < m)
				{
					if (grid[x][y] == '1' && !visited[x][y])
					{
						visited[x][y] = true;
						q.push({x, y});
					}
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		n = grid.size();
		if (!n) return 0;

		m = grid[0].size();

		int cnt = 0;
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					cnt++;
					visited[i][j] = true;
					bfs(i, j, grid, visited);
				}
			}
		}
		return cnt;
	}
};
