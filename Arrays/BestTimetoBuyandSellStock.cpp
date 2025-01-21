#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // will maintain a minimum price and as we move through the time (prices) will calculate the profit
        //  as well as update the minPrice if price drops
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};