class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int ans = 0;
        for(int i = 0;i<32;i++)
        {
            int mask = 1<<i; // Mask to find the ith bit
            int cur_bit = n & mask ? 1 : 0; // Checking whether the ith bit is on or not
            
            if(cur_bit)
            {
                ans |= 1<<(31-i); // Turning on the reversed bit
            }
            
        }
        
        return ans;
    }
};
