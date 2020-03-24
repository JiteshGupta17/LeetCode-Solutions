class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0; // Bit after which the nos are same
        
        // Found the Common leftmost part
        while(m!=n)
        {
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        
        // Adding count no. of zeroes to the right of common leftmost part
        return m << count;
    }
};
