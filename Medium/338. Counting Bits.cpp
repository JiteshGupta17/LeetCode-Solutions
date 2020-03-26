// Method 1 - Trivial DP solution  
// dp[1] = dp[1-1] + 1;

// dp[2] = dp[2-2] + 1;

// dp[3] = dp[3-2] +1;

// dp[4] = dp[4-4] + 1;

// dp[5] = dp[5-4] + 1;

// dp[6] = dp[6-4] + 1;

// dp[7] = dp[7-4] + 1;

// dp[8] = dp[8-8] + 1;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp (num+1,0);
        
        int two_power = 1;
        
        for(int i = 1;i<=num;i++)
        {
            if(two_power*2==i)
            {
                // power of two
                two_power *= 2;
            }
            
            dp[i] = dp[i-two_power] + 1;
        }
        
        return dp;
    }
};

// Method 2 - Observing another pattern
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0); 
        
        for ( int i = 1; i <= num; i++ ) {
            // add 1 only when i i.e no. is odd
            dp[i] = dp[i/2] + i % 2;
        }
        return dp;
    }
};
