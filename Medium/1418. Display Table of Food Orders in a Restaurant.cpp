class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        map<int,map<string,int>> mp;
        set<string> fooditems;
        
        for(auto vec : orders)
        {
            fooditems.insert(vec[2]);
            mp[stoi(vec[1])][vec[2]]++;
        }
        
        vector<vector<string>> ans(mp.size() +1,vector<string>(fooditems.size()+1,"0"));
        
        ans[0][0] = "Table";
        
        int idx = 1;
        for(auto it : fooditems)
        {
            ans[0][idx] = it;
            idx++;
        }
        
        idx = 1;
        for(auto it : mp)
        {
            ans[idx][0] = to_string(it.first);
            int i = 1;
            
            for(auto ele : fooditems)
            {
                if(mp[it.first].count(ele))
                {
                    ans[idx][i] = to_string(mp[it.first][ele]);
                }
                i++;
            }
            idx++;
        }
        
        return ans;
    }
};
