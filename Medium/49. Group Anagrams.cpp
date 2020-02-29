class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Sort each string which acts as key in the map
        unordered_map<string,vector<string>> m;
        
        vector<vector<string>> ans;
        
        for(string s : strs)
        {
            string cur = s;
            sort(s.begin(),s.end());
            
            m[s].push_back(cur);
            
        }
        
        for(auto ele : m)
        {
            ans.push_back(ele.second);
        }
        
        return ans;
        
    }
};
