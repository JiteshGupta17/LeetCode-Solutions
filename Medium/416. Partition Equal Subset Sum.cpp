
// Method 1 - Using recursion , wont pass
bool canPartition(vector<int>& nums) {
    return partition(nums, 0, 0, 0);

}
bool partition(vector<int>& nums, int sum1, int sum2, int idx)
{
    if (idx == nums.size())
    {
        if (sum1 == sum2) return true;
        return false;
    }
    return partition(nums, sum1 + nums[idx], sum2, idx + 1) || partition(nums, sum1, sum2 + nums[idx], idx + 1);
}

// =========================================================================================================================

// Method 2 -  Using 2D-DP Same as Knapsack
bool canPartition(vector<int>& nums) {


    int sum = 0;
    for (int ele : nums) sum += ele;

    if (sum & 1) return false;

    //Now the ques is whether we can make sum/2 from array elements
    sum = sum / 2;

    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= nums.size(); i++)
    {
        int ele = nums[i - 1];
        for (int cur_sum = 0; cur_sum <= sum; cur_sum++)
        {
            if (cur_sum >= ele)
                dp[i][cur_sum] = dp[i - 1][cur_sum - ele];

            dp[i][cur_sum] = dp[i][cur_sum] || dp[i - 1][cur_sum];
        }
    }

    return dp[nums.size()][sum];

}

// =========================================================================================================================

// Method 3 - Using 1D-DP
bool canPartition(vector<int>& nums) {

    int sum = 0;
    for (int ele : nums) sum += ele;

    if (sum & 1) return false;

    //Now the ques is whether we can make sum/2 from array elements
    sum = sum / 2;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int ele : nums)
    {
        for (int cur_sum = sum; cur_sum >= 0; cur_sum--) // NOTE : In decreasing,To be start from sum till 0
        {
            if (cur_sum >= ele)
                dp[cur_sum] = dp[cur_sum] || dp[cur_sum - ele];

        }
    }

    return dp[sum];

}
