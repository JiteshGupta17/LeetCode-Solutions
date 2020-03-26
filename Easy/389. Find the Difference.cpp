class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int r = 0;
        for(char ch : s)
        {
            r ^= ch;
        }
        
        int val_t = 0;
        for(char ch : t)
        {
            r ^= ch;
        }
        
        return r;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int val_s = 0;
        for(char ch : s)
        {
            int mask = 1<<(ch-'a');
            // if already set then unset else set
            val_s  = (val_s & mask)!=0 ? val_s & ~mask : val_s | mask;
        }
        
        int val_t = 0;
        for(char ch : t)
        {
            int mask = 1<<(ch-'a');
            // if already set then unset else set
            val_t  = (val_t & mask)!=0 ? val_t & ~mask : val_t | mask;
        }
        
        int cur = val_s ^ val_t;
        int posi = 0;
        
        while((cur&1) != 1)
        {
            posi++;
            cur = cur>>1;
        }
        
        return char('a' + posi);
    }
};
