// Buy and Sell Stocks With Transaction Fee

class Solution {
public:
    // buy : 1
    // sell : 0
    int helper(vector<int>& prices, int fee, int index, int buy, vector<vector<int>>& dp)
    {
        if(index == prices.size())
        {
            return 0;
        }
        if(dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] - fee + helper(prices, fee, index+1, 0, dp), 0 + helper(prices, fee, index+1, 1, dp));
        }
        else
        {
            profit = max(prices[index] + helper(prices, fee, index+1, 1, dp), 0 + helper(prices, fee, index+1, 0, dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return helper(prices, fee, 0,1, dp);
    }
};