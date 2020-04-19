class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        // int maxi = 0;
        unordered_map<char,int> mp;
        
        mp['c'] = 0;
        mp['r'] = 0;
        mp['o'] = 0;
        mp['a'] = 0;
        mp['k'] = 0;
        
        int maxi=  0;
        int ans = 0;
        int free = 0;
        
        
        for(char ch : croakOfFrogs)
        {
            mp[ch]++;
            
            if(ch=='c')
            {
                if(free==0) ans++;
                else free--;
            }
            
            if(ch=='r' && mp['r'] > mp['c']) return -1;
            if(ch=='o' && mp['o'] > mp['r']) return -1;
            if(ch=='a' && mp['a'] > mp['o']) return -1;
            
            if(ch=='k') 
            {
                if( mp['k'] > mp['a']) return -1;
                else free++;
            }
            
            maxi = max(maxi,mp[ch]);
            
        }
        
        for(auto ele : mp)
        {
            if(ele.second != maxi) return -1;
        }

        return ans;
        
    }
};
