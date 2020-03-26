class Solution {
public:
    int getSum(int a, int b) {
        // 3 + 2 is with carry and 1 + 2 is without carry
        // and without carry addition can simply be done with xor but to produce carry
        // we need to do and shift it one position left
        
        // b will act as carry
        int c;
        while(b)
        {
            c = a&b; // To produce carry
            a = a^b; // Addition in case of no carry
            b = (unsigned int)(c)<<1; // The right carry and unsgined int to prevent left shift of negative nos
        }
        
        return a;
    }
};
