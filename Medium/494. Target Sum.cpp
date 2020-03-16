// Using DP and similiar to divide in sets - 4ms
class Solution {
public:
    /*
        https://leetcode.com/problems/target-sum/

        The given sets can be considered as P and N. where N contains the numbers of other set which are
        subtracted.
        P - N = Target(T)
        P + N = S
        2P = T + S
        P = (T + S) / 2

        => (T + S) should be even and P = (T + S)/2
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        for (int num : nums) total += num;

        if (S > total || (S + total) & 1) return 0;

        int required_positive = (S + total) / 2;

        vector<int> dp(required_positive + 1, 0);

        dp[0] = 1;
        for ( int num : nums) {
            // starting from back to avoid addition of redundant terms with the
            // lower values when doing dp[i - num]
            for (int i = required_positive; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        return dp[required_positive];

    }
};

// Using hashMap and recursion - 300ms
class Solution {
public:
    map<pair<int, long long int>, int> mp;

    long long int TargetSum(int i, vector<int>& nums, long long int sum, int S)
    {
        if (i == nums.size())
        {
            if (S == sum) return 1;
            return 0;
        }
        if (mp.find({i, sum}) != mp.end()) return mp[ {i, sum}];

        int plus = TargetSum(i + 1, nums, sum + nums[i], S);
        int minus = TargetSum(i + 1, nums, sum - nums[i], S);

        mp[ {i, sum}] = plus + minus;

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return TargetSum(0, nums, 0, S);
        mp.clear();
    }
};
