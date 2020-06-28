class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++)
        {
            int rem = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;

            while (l < r)
            {
                if (nums[l] + nums[r] == rem)
                {
                    if (ans.empty() || !(ans.back()[1] == nums[l] && ans.back()[2] == nums[r]))
                    {
                        ans.push_back({nums[i], nums[l], nums[r]});
                    }
                    
                    l++, r--;
                }
                else if (nums[l] + nums[r] > rem)
                {
                    r--;
                }
                else l++;
            }
        }

        return ans;
    }
};