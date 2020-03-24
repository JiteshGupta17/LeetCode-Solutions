// Method 1 - Time O of total no. of set bits
class Solution {
public:
    int hammingWeight(uint32_t n) {

        int ans = 0;
        while(n)
        {
            ans++;
            n = n & (n-1);
        }
        
        return ans;
        
    }
};

// Method 2 - Time O of total no. of bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int ans = 0;
        while(n)
        {
            if(n&1) ans++;
            n = n>>1;
        }
        return ans;
        
    }
};

