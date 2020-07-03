// Using DFS
class Solution {
public:

    vector<int> color;
    vector<bool> visited;
    bool bipartite = true;

    void dfs(int cur, vector<vector<int>>& graph, int col)
    {
        visited[cur] = true;
        color[cur] = col;

        for (auto x : graph[cur])
        {
            if (!visited[x]) {
                dfs(x, graph, 3 - col);
            }
            else {
                if (color[x] == col)
                {
                    bipartite = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        // Graph is not bipartite if and ony if it contains a cycle of odd length

        int n = graph.size();
        color.resize(n), visited.resize(n);

        int col = 1;
        for (int i = 0; i < n; i++)
        {
            // As graph might have various connected components
            if (!visited[i])
            {
                dfs(i, graph, col);
                if (!bipartite) return false;
            }
        }

        return true;
    }
};
////////////////////////////////////////////////////////////////////////////////////////

// Using BFS
class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n);

        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int nbr : graph[cur])
                {
                    if (!visited[nbr])
                    {
                        visited[nbr] = 3 - visited[cur];
                        q.push(nbr);
                    }
                    else if (visited[nbr] == visited[cur])
                    {
                        return false;
                    }
                }
            }

        }

        return 1;

    }
};