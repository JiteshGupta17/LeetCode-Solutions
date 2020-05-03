class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        string ans = "";
        unordered_map<string,int> mp;
        
        for(auto vec : paths)
        {
            if(mp.find(vec[1]) == mp.end()){
                mp[vec[1]] = 0;
            }
            mp[vec[0]]++;
        }
        
        for(auto ele : mp)
        {
            if(ele.second==0) return ele.first;
        }
        
        return ans;
    }
};
