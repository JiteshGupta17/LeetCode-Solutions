class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int req1 = target - nums[i] - nums[j];

                int l = j + 1, r = n - 1;

                while (l < r)
                {
                    if (nums[l] + nums[r] == req1)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while (l + 1 < r - 1 && nums[l] == nums[l + 1] && nums[r] == nums[r - 1]) {
                            l++, r--;
                        }
                        l++, r--;

                    }
                    else if (nums[l] + nums[r] > req1) {
                        r--;
                    }
                    else l++;
                }

            }
        }

        return ans;
    }
};