// Union Find
class Solution {
public:

    int find(int x, vector<int>&parent)
    {
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x], parent);
    }

    int findCircleNum(vector<vector<int>>& M) {
        int total_components = M.size();

        vector<int> parent(M.size());

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M.size(); j++)
            {
                if (M[i][j] == 1)
                {
                    int super_parent_i = find(i, parent);
                    int super_parent_j = find(j, parent);

                    if (super_parent_i != super_parent_j)
                    {
                        parent[super_parent_i] = super_parent_j;
                        total_components--;
                    }
                }
            }
        }

        return total_components;
    }
};

// ================================================================================================

// DFS
class Solution {
public:

    void dfs(int cur, vector<bool>&visited, vector<vector<int>>& M)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (M[cur][j] && !visited[j])
            {
                visited[j] = true;
                dfs(j, visited, M);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        int total_components = 0;

        vector<bool> visited(N, false);

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                total_components++;
                dfs(i, visited, M);
            }
        }

        return total_components;
    }
};
