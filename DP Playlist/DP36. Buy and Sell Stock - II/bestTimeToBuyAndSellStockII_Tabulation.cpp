// Best Time to Buy and Sell Stock II - Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));  // 1 for buy and 2 for sell
        dp[0][1] = 0;
        dp[0][0] = 0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[index][buy] = max(-prices[index] + dp[index+1][0], // buy the stock
                                                0 + dp[index+1][1]); // not buy the stock
                }

                // for selling the stock if buy == 0
                else
                {
                    dp[index][buy] = max(prices[index] + dp[index+1][1], // sell the stock
                                                0 + dp[index+1][0]); // not sell the stock
                }
            }
        }
        return dp[0][1];
    }
};