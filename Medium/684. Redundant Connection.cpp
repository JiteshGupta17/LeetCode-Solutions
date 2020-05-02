class Solution {
public:
    
    // Path Compression
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x]) return x;
        
        return parent[x] = find(parent[x],parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(edges.size() + 1,0); // initilaise with zero as 0 not a valid vertex
        
        for(auto& e : edges)
        {
            int u = e[0], v = e[1];
            if(parent[u] == 0) parent[u] = u;
            if(parent[v] == 0) parent[v] = v;
            
            int super_parent_u = find(u,parent);
            int super_parent_v = find(v,parent);
            
            // Both lie under same parent then cycle exist if this edge is added
            if(super_parent_u == super_parent_v)
            {
                return e;
            }
            else{
                parent[super_parent_v] = super_parent_u;
            }
        }
        
        return vector<int>();
        
    }
};
