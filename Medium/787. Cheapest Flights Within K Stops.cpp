
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Node {
public:

    int nodesIntBtw;
    int dist;
    int node;

    Node(int a, int b, int c)
    {
        nodesIntBtw = a;
        dist = b;
        node = c;
    }

};

struct compare {
    bool operator()(const Node &a, const Node &b)
    {
        return a.dist >= b.dist;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<list<pair<int, int>>> graph(n);
        for (auto vec : flights)
        {
            graph[vec[0]].push_back({vec[1], vec[2]});

        }

        priority_queue<Node, vector<Node>, compare> pq;
        pq.push(Node(0, 0, src));

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int cur_node = cur.node;

            if (cur_node == dst) return cur.dist;

            for (auto ch : graph[cur_node])
            {
                int child_node = ch.first;
                int wt = ch.second;

                if (cur.nodesIntBtw <= K)
                {
                    pq.push(Node(cur.nodesIntBtw + 1, cur.dist + wt, child_node));
                }
            }
        }

        return -1;
    }
};
