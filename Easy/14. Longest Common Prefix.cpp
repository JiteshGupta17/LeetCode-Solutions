class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        if(strs.size()==1) return strs[0];
        
        int ShortestStringIdx = 0;
        int len = strs[0].length();
        // Find the shortest length string
        for(int i = 0;i<strs.size();i++)
        {
            if(strs[i].length() < len)
            {
                len = strs[i].length();
                ShortestStringIdx = i;
                
            }
        }
              
        string ans = "";
        for(int i = 0;i<len;i++)
        {
            bool f = true;
            
            for(int j = 1;j<strs.size();j++)
            {
                if(strs[j-1][i] != strs[j][i]){
                    f = false;
                    break;
                }
            }
            
            if(!f) break;
            ans += strs[0][i];
        }
        
        return ans;
    }
};
