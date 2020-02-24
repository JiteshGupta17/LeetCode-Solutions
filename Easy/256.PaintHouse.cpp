#include<bits/stdc++.h>
using namespace std;

// Recursive if no of paints larger
int paintHouse(vector<vector<int>> cost,int cur_row,vector<bool> &prevUsed)
{
    if(cur_row==cost.size())
    {
        return 0;
    }

    vector<bool> curUsed(3,false);

    int min_cost = INT_MAX;

    for(int i = 0;i<3;i++)
    {
        if(!prevUsed[i])
        {
            curUsed[i] = true;
            min_cost = min(min_cost,cost[cur_row][i] + paintHouse(cost,cur_row+1,curUsed));
            curUsed[i] = false;
        }
    }

    return min_cost;
}

int paintHouse_Dp(vector<vector<int>> costs)
{
    if(costs.size()==0) return 0 ;

    int n = costs.size();
    // Without Extra Space
    for(int i = 1;i<costs.size();i++)
        {
                costs[i][0] += min(costs[i-1][1],costs[i-1][2]);
                costs[i][1] += min(costs[i-1][0],costs[i-1][2]);
                costs[i][2] += min(costs[i-1][1],costs[i-1][0]);
        }

    return min(costs[n-1][0],min(costs[n-1][1],costs[n-1][2]));

    // With Extra Space

    // vector<vector<int>> dp(costs.size(),vector<int>(3,INT_MAX/2));

    // for(int i = 0;i<costs.size();i++)
    // {
    //     if(i==0)
    //     {
    //         dp[i] = costs[i]
    //     }
    //     else{
    //         dp[i][0] = cost[i][0] + min(dp[i-1][1],dp[i-1][2]);
    //         dp[i][1] = cost[i][1] + min(dp[i-1][0],dp[i-1][2]);
    //         dp[i][2] = cost[i][2] + min(dp[i-1][1],dp[i-1][0]);
    //     }
    // }

    // for(auto v : dp)
    // {
    //     for(int ele : v) cout<<ele<<" ";
    //     cout<<endl;
    // }

    // return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));

}

int main() {

    vector<vector<int>> cost = {{14,2,11},{11,14,5},{14,3,10},{4,2,3},{4,2,3}};

    // vector<bool> prevUsed(3,false);
    // cout<< paintHouse(cost,0,prevUsed)<<endl;
    cout<<paintHouse_Dp(cost);


}