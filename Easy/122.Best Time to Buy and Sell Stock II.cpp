#include <bits/stdc++.h>
using namespace std;

int maxProfit_recur(vector<int>prices, int i, int buy_price)
{
    if (i == prices.size())
    {
        return 0;
    }

    int ans1 = 0, ans2 = 0;
    if (prices[i] > buy_price)
    {
        ans1 = prices[i] - buy_price + maxProfit_recur(prices, i + 1, INT_MAX);
        ans2 = maxProfit_recur(prices, i + 1, buy_price);
        return max(ans1, ans2);
    }

    return maxProfit_recur(prices, i + 1, prices[i]);

}

int maxProfit(vector<int> prices)
{
    // Peak Valley Approach
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        max_profit += max(0, prices[i] - prices[i - 1]);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 6, 4, 3, 1};

    cout << maxProfit_recur(prices, 1, prices[0]) << endl; // Recursive exponential time
    cout << maxProfit(prices) << endl; // linear time
}
