class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> sizes(n+1);
        vector<vector<int>> ans;
        
        for(int i = 0;i<groupSizes.size();i++)
        {
            int cur = groupSizes[i];
            sizes[cur].push_back(i);
           
            
            if(sizes[cur].size() == cur)
            {
                ans.push_back(sizes[cur]);
                sizes[cur] = {};
            }
        }
        return ans;
    }
};
