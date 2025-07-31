// Best Time to Buy and Sell Stock II - Memoization

class Solution {
public:
    int helper(vector<int>& prices, int index, int buy, vector<vector<int>> &dp)
    {
        if(index==prices.size())
        {
            return 0;
        }

        if(dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        if(buy)
        {
            return dp[index][buy] = max(-prices[index] + helper(prices,index+1,0,dp), // buy the stock
                                        0 + helper(prices,index+1,1,dp)); // not buy the stock
        }

        // for selling the stock if buy == 0
        return dp[index][buy] = max(prices[index] + helper(prices,index+1,1,dp), // sell the stock
                                    0 + helper(prices,index+1,0,dp)); // not sell the stock
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));  // 1 for buy and 0 for sell
        return helper(prices, 0, 1, dp); // initial state will be buy i.e. 1
    }
};