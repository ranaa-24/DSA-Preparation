
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // we can buy and sell as many time as we can..
        // just draw a graph of price and its simple, we may buy on some low cost day and and sell it on next high cost.
        int buy, sell, i, N, profit;
        buy = profit = sell = i = 0;
        N = prices.size() - 1;
        while (i < N)
        {
            // Buy when the price a bit low, all price same? wont buy.. profit 0
            while (i < N && prices[i] >= prices[i + 1])
                i++;
            buy = prices[i];

            // sell when the price is bit high
            while (i < N && prices[i] < prices[i + 1])
                i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};

// OR: just sell it if the price is higher than the previous day.
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};