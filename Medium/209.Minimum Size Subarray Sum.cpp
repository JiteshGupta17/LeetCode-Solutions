#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {

    int n = nums.size();
    int r = 0;
    int ans = n + 1;
    int cumulative = 0;

    for (int l = 0; l <= min(r, n - 1); l++)
    {
        while (r < n && cumulative + nums[r] < s)
        {
            cumulative += nums[r];
            r++;
        }

        if (r < n && cumulative + nums[r] >= s)
            ans = min(ans, r - l + 1 );

        cumulative -= nums[l];
        // cout<<l<<" "<<ans<<endl;

    }

    return ans <= n ? ans : 0;
}

int main() {

    vector<int> nums = {11};
    cout << minSubArrayLen(11, nums);
}
