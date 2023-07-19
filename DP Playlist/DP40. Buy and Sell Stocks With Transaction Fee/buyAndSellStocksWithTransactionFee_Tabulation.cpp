// Buy and Sell Stocks With Transaction Fee - Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[index][buy] = max(-prices[index] - fee + dp[index+1][0],
                                         0 + dp[index+1][1]);
                }
                else
                {
                    dp[index][buy] = max(prices[index] + dp[index+1][1],
                                         0 + dp[index+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};