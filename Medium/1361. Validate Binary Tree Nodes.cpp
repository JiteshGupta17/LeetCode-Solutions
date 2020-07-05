class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    bool c = 1;

    void dfs(int cur)
    {
        visited[cur] = 1;

        for(int nbr : graph[cur])
        {
            if(!visited[nbr]) dfs(nbr);
            else c = 0;
        }
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        
        graph.resize(n);
        visited.resize(n);
        
        vector<int> indegree(n);
        
        for(int i = 0;i<n;i++)
        {
            if(left[i] != -1) {
                indegree[left[i]]++;
                graph[i].push_back(left[i]);
            }
            if(right[i] != -1){
             graph[i].push_back(right[i]);
             indegree[right[i]]++;
            }
        }
        
        int start = -1;
        for(int i = 0;i<n;i++){
            int ele = indegree[i];
            if(ele==0)
            {
                if(start==-1) start = i;
                else return false;
            }
        }
        if(start==-1) return false;
        dfs(start);
        
        for(int i = 0;i<n;i++) if(!visited[i]) return false;

        return c;
    }
};

