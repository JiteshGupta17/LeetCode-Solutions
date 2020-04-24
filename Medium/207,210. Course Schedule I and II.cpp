// VVIP - If course u is a prerequisite of course v, then the adjacency list of u will contain v.

// BFS - 28 ms
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<list<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // costructing the graph and calculating indegree
        for (auto& vec : prerequisites) {

            graph[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }

        // pushing nodes with zero indegree(zero prerequisite) in queue
        queue<int>q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> ordering;
        int cnt = 0; // No of nodes visited

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            cnt++;

            ordering.push_back(cur);

            for (auto& nbrs : graph[cur])
            {
                indegree[nbrs]--; // if prvsly 0 then will go to -1 so will work as visited also
                if (indegree[nbrs] == 0)
                {
                    q.push(nbrs);
                }
            }
        }

        return cnt == numCourses ? ordering : vector<int>();

    }
};

// ==================================================================================================

// DFS - 32 ms
class Solution {
    vector<list<int>> graph;
    list<int> ordering; // To maintain the ordering

public:

    bool dfs(int node, vector<bool> &visited, vector<bool> &stack)
    {
        // Visit the current node and add it into stack
        visited[node] = true;
        stack[node] = true;

        for (auto & nbrs : graph[node])
        {
            // two cases

            // 1.
            if (stack[nbrs]) return true;

            // 2.
            if (!visited[nbrs] && dfs(nbrs, visited, stack))
                return true;
        }

        // Current node still remains visited but it exits the stack
        stack[node] = false;
        ordering.push_front(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        graph.resize(numCourses);

        for (auto& vec : prerequisites) {

            graph[vec[1]].push_back(vec[0]);
        }

        vector<bool> visited(numCourses, false), stack(numCourses, 0); // whick all nodes in stack

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                bool cycle = dfs(i, visited, stack);
                if (cycle) return vector<int> ();
            }
        }

        return vector<int> (ordering.begin(), ordering.end());

    }
};
