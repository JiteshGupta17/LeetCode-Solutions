class Solution {
public:

    vector<int> graph[2001];
    int visited[2001] = {};
    bool bipart = 1;

    void dfs(int cur)
    {
        for (int nbr : graph[cur])
        {
            if (!visited[nbr])
            {
                visited[nbr] = 3 - visited[cur];
                dfs(nbr);
            }
            else if (visited[nbr] == visited[cur])
            {
                bipart = false;
                return ;
            }
        }
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        for (auto vec : dislikes)
        {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                dfs(i);

                if (!bipart) return false;
            }
        }

        return true;
    }
};