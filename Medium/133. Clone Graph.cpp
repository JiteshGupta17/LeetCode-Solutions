// BFS
class Solution {
    unordered_map<Node*, Node*> graph;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        Node* main = new Node(node->val);
        graph[node] = main;

        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto child : cur->neighbors)
            {
                // This line below will not work here before as we are not cloning and
                // directly adding the given node
                // graph[cur]->neighbors.push_back(child);
                if (graph.find(child) == graph.end())
                {
                    Node* temp = new Node(child->val);
                    graph[child] = temp;
                    q.push(child);
                }

                // Here it will work because we have made a new node if it was not their previously
                // and then added that
                graph[cur]->neighbors.push_back(graph[child]); // graph[child] = temp, is clone of child
            }
        }

        return main;

    }
};

// ==============================================================================================================================

// DFS
class Solution {
    unordered_map<Node*, Node*> graph;
public:

    Node* dfs(Node* node)
    {
        if(!node) return NULL;

        graph[node] = new Node(node->val);

        for (auto child : node->neighbors)
        {
            if (graph.find(child) == graph.end()) {

                dfs(child); // This will automatically clone it
            }

            graph[node]->neighbors.push_back(graph[child]);
        }

        return graph[node];
    }

    Node* cloneGraph(Node* node) {

        return dfs(node);

    }
};

