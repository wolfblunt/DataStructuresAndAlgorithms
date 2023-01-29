// Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int buySellStock(int index, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        // 1 means buy the stock
        // 0 means sell the stock
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];

        // no transaction on that day
        int cost1 = 0 + buySellStock(index+1, buy, prices, dp);
        int cost2 = 0;
        if(buy==1)
        {
            cost2 = -prices[index] + buySellStock(index+1, 0, prices, dp);
        }
        else
        {
            cost2 = prices[index] + buySellStock(index+2, 1, prices, dp);
        }
        return dp[index][buy] = max(cost1, cost2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));  // because buy has 2 options i.e either buy or not buy
        return buySellStock(0, 1, prices, dp);
    }
};