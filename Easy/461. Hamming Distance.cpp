// if bits same then 0 and if different then 1 which is obtained by xor operation, so now 
// we just need to count the no. of set bits in result
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int result = x^y;
        int ans = 0;
        
        while(result)
        {
            ans++;
            result = result & (result-1);
        }
        
        return ans;
        
    }
};
