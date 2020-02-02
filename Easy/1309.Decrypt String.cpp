class Solution {
public:
    string freqAlphabets(string s) {
        
        int n = s.length();
        
        string ans = "";
        
        for(int i = 0;i<n;i++)
        {
            if(i+2 < n && s[i+2]=='#')
            {
                int num = (s[i] - '0')*10 + (s[i+1] - '0');
                char cur = char('a' + num - 1);
                ans += cur;
                i += 2;
            }
            else{
                int num = s[i] - '0';
                char cur = char('a' + num - 1);
                ans += cur;
            }
        }
        
        return ans;
        
    }
};