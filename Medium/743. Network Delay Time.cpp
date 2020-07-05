class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<int> dist(N+1,1e9);
        vector<pair<int,int>> graph[N+1];
        
        for(auto vec : times)
        {
            graph[vec[0]].push_back({vec[1],vec[2]});
        }
        
        dist[K] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,K});
        
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            
            if(dist[cur.second] < cur.first) continue;
            
            for(auto nbr : graph[cur.second])
            {
                if(dist[nbr.first] > nbr.second + cur.first)
                {
                    dist[nbr.first] = nbr.second + cur.first;
                    pq.push({dist[nbr.first],nbr.first});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1;i<=N;i++)ans = max(ans,dist[i]);
        
        return ans==1e9 ? -1 : ans;
    }
};
