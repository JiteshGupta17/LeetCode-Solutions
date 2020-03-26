// 26 in binary is 0001 1010
// and to convert it in hexa we take four bits at a time 1 and a therefore
class Solution {
public:
    string toHex(int num) {
        
        string ans = "";
        
        int i = num;
        int max_itr = 8; // As 32 bit divided into 4 each time gives max of 8 digit hexa
        
        while(i && max_itr--)
        {
            int x = i&15; // To extract the first 4 bits from LSB
            
            if(x >=10)
            {
                ans =  char('a' + x - 10) + ans;
            }
            else{
                ans = to_string(x) + ans;
            }
            
            i = i>>4; // Discarding the first 4 bits by shifting the number to right by times
        }
        
        if(ans.length()==0)
            return "0";
        
        return ans;
    }
};
