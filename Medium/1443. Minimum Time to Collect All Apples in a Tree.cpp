class Solution {
public:
    
    vector<vector<int>> graph;
    int ans = 0;
    
    // whether there is an apple below node
    bool dfs(int node, vector<bool>& hasApple, vector<bool>& visited )
    {
        // cout<<node<<endl;
        bool cur = false;
        for(int ele : graph[node])
        {
            if(!visited[ele])
            {
                visited[ele] = true;
                bool res = dfs(ele,hasApple,visited) ;
                
                // if there is an apple below or on current then we must travel this edge
                if(res || hasApple[ele]){
                    ans+=2;
                    cur = true;
                }  
            }    
        }   
       return cur;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);
        
        for(auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
        }
    
        vector<bool> visited(n,false);
        
        visited[0] = true;
        dfs(0,hasApple,visited);
        
        return ans;
    }
};
