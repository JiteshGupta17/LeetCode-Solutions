class Solution {
public:

	// int dp[501][501][2];
	int dp[501][501];

	int helper(int i, int j , vector<int>&nums1, vector<int>&nums2)
	{
		if (i == nums1.size() || j == nums2.size())
		{
			return -1e6;
		}

		if (dp[i][j] != -1) return dp[i][j];

		int cur_ans = nums1[i] * nums2[j] + max(0, helper(i + 1, j + 1, nums1, nums2));
		cur_ans  = max(cur_ans, helper(i + 1, j, nums1, nums2));
		cur_ans = max(cur_ans, helper(i, j + 1, nums1, nums2));

		return dp[i][j] = cur_ans;
	}

	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		memset(dp, -1, sizeof dp);
		return helper(0, 0, nums1, nums2);
	}
};

//=============================================================================

class Solution {
public:

	int dp[501][501][2];

	int helper(int i, int j , vector<int>&nums1, vector<int>&nums2, bool f)
	{
		if (i == nums1.size() || j == nums2.size())
		{
			if (f) return 0;
			return -1e6;
		}

		if (dp[i][j][f] != -1) return dp[i][j][f];

		int cur_ans = nums1[i] * nums2[j] + helper(i + 1, j + 1, nums1, nums2, true);
		cur_ans  = max(cur_ans, helper(i + 1, j, nums1, nums2, f));
		cur_ans = max(cur_ans, helper(i, j + 1, nums1, nums2, f));

		return dp[i][j][f] = cur_ans;
	}

	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		memset(dp, -1, sizeof dp);
		return helper(0, 0, nums1, nums2, 0);
	}
};
