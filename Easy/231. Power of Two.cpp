// Method 1 - Using Bitset
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n)
        {
            if (n & 1 && n != 1) return false;
            n = n >> 1;
        }

        return true;
    }
};

// Method 2 - Same as using bitset but using arithmatic
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
};

// Method 3 - As only 1 bit of n will be set , imagine with 8 and 7
class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n > 0 && ((n & (n - 1)) == 0);
    }
};

// Method 4 - only 1 set bit in powers of 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // As only 1 bit of n will be set , imagine with 8 and 7
        bitset<32> b1(n);
        return n > 0 && b1.count() == 1;
    }
};

