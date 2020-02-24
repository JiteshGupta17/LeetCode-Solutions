#include<bits/stdc++.h>
using namespace std;

// Faith = Each element stores the max amount that can be steal upto it from start

int rob(vector<int>& nums,int n) {
    if(n==1)
    {
        return nums[0];
    }

    if(n==2)
    {
        return max(nums[0],nums[1]);
    }

    return max(rob(nums,n-2) + nums[n-1],rob(nums,n-1));
}

int rob_DP(vector<int> nums)
{
    int n = nums.size();

    if(n==0) return 0;
    vector<int> dp(n,0);

    for(int i =0;i<n;i++)
    {
        if(i==0){
            dp[i] = nums[i];
            continue;
        }

        if(i==1)
        {
            dp[i] = max(nums[0],nums[1]);
            continue;
        }

        dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
    }

    // for(int ele : dp) cout<<ele<<" ";

    return dp[n-1];
}

int main() {

    
    std::vector<int> v = {2,1,3,2,1,3};
    // cout<<rob(v,v.size());
    cout<<rob_DP(v);
    

}