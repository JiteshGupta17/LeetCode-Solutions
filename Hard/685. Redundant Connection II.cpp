class Solution {
public:
    vector<int> ans;
    
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x],parent);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // NOTE: According to ques, no node can have more than one parent
        
        int n = edges.size();
        vector<int> parent(n+1,0), candA,candB;
        
        for(auto &e : edges)
        {
            if(parent[e[1]]==0)
            {
                parent[e[1]] = e[0];
            }
            else{
                
                candA = {parent[e[1]],e[1]};
                candB = e;
                e[0] = 0, e[1] = 0;
                // After setting this invalid, if union find works fine then ans in candB
            }
        }
        
        for(int i = 1;i<=n;i++) parent[i] = i;
        
        for(auto e : edges)
        {
            if(e[0]==0 && e[1]==0) continue;
            
            int sp1 = find(e[0],parent);
            int sp2 = find(e[1],parent);
        
            
            if(sp1==sp2)
            {
                // Union Find finds a cycle
                if(!candA.empty()) return candA;
                return e;
            }
            else parent[sp2] = sp1;
        }
        
        
        return candB;
        
    }
};
