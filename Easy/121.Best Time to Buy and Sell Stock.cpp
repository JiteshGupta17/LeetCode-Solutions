#include <bits/stdc++.h>
using namespace std;

int maxProfit_recur(vector<int>  prices, int i, int buy_price)
{
    if (i == prices.size()) return 0;

    int ans1 = 0;
    int ans2 = 0;

    if (prices[i] - buy_price > 0 && i != 0)
    {
        ans1 = max(prices[i] - buy_price, maxProfit_recur(prices, i + 1, buy_price));
    }
    else {
        ans2 = maxProfit_recur(prices, i + 1, prices[i]);
    }

    return max(ans1, ans2);
}

int maxProfit(vector<int>prices)
{
    int buy_price = 0;
    int max_sell = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (i != 0 && prices[i] > buy_price)
        {
            max_sell = max(max_sell, prices[i] - buy_price);
        }
        else {
            buy_price = prices[i];
        }
    }

    return max_sell;
}

int main() {
    vector<int>  prices = {2, 1, 2, 1, 0, 1, 2};

    cout << maxProfit_recur(prices, 0, 0) << endl;
    cout << maxProfit(prices) << endl;
}
