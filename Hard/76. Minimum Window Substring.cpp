class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> tset(256,0); // 256 is total no of characters present
        for(char ch : t) tset[ch]++;
        int t_len = t.length();
        
        int n = s.length();
        
        int cur_cnt = 0; // gives total no of characters in r-l which are required
        
        int min_len = n+1;
        int start = 0;
        int r = 0;
        
        for(int l = 0;l<n;l++)
        {
            while(r < n && cur_cnt!=t_len)
            {
                if(tset[s[r]]>0) // Valid character goes inside window
                    cur_cnt++;
                
                tset[s[r]]--;
                r++;
            }
            
            if(cur_cnt==t_len && min_len > r-l)
            {
                start = l;
                min_len = r-l;
            }
            
            if(tset[s[l]]==0) cur_cnt--; // Valid Character out of window
            
            tset[s[l]]++;
        }
        
        return min_len == n+1 ? "" : s.substr(start,min_len);
        
    }
};
