class Solution {
public:

    // https://leetcode.com/problems/find-k-th-smallest-pair-distance/

    int check(int mid, vector<int>&nums)
    {
        int n = nums.size();
        int ans = 0;
        int en = 0;
        for (int st = 0; st < n; st++)
        {
            while (en + 1 < n && (nums[en + 1] - nums[st]) <= mid)
            {
                en++;
            }

            ans += en - st;
            // cout<<st<<" "<<en<<endl;
        }

        return ans;
    }

    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int r = nums.back() - nums[0]; //max Distance
        int l = 0;  // Min Distance
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            // no of pairs with dist <= mid
            // suppose k - 4 and we get check as 6 means it can be the possible ans
            // and we need to minimise the distance so that value of check reduces
            if (check(mid, nums) >= k)
            {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;

    }
};
