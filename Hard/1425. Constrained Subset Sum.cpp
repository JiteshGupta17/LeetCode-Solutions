class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        deque<int> deque;
        deque.push_back(n);

        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            // Update deque by removing the ones which are not in range,
            // will work with if (usually we use while) as we are updating it each time
            if (i + k < deque.back())
            {
                deque.pop_back();
            }

            dp[i] = nums[i] + max(0, dp[deque.back()]);
            ans = max(ans, dp[i]);

            // Update deque by removing smaller elements than current
            while (!deque.empty() && dp[i] >= dp[deque.front()])
            {
                deque.pop_front();
            }

            deque.push_front(i);

        }

        return ans;
    }
};
