#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int MinCostClimb(vector<int> cost, int n)
{
    if (n <= 1) return 0;

    int cost_1 = cost[n - 1] + MinCostClimb(cost, n - 1);
    int cost_2 = cost[n - 2] + MinCostClimb(cost, n - 2);

    return min(cost_1, cost_2);

}

// Using DP
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            dp[i] = 0;
        }
        else {
            int cost_1 = cost[i - 1] + dp[i - 1];
            int cost_2 = cost[i - 2] + dp[i - 2];
            dp[i] = min(cost_1, cost_2);
        }
    }

    // for(int i = 0;i<=n;i++) cout<<dp[i]<<" ";
    // cout<<endl;

    return dp[n];
}
int main() {
    vector<int> cost = {0, 1, 1, 0};
    // cout<<MinCostClimb(cost,cost.size()); // Using Recursion

    cout << minCostClimbingStairs(cost); // Using Dp
}