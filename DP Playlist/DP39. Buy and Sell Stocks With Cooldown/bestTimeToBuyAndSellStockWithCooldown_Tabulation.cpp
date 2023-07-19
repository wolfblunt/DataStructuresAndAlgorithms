// Best Time to Buy and Sell Stock with Cooldown - Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[index][buy] = max(-prices[index] + dp[index+1][0],
                                         0 + dp[index+1][1]);
                }
                else
                {
                    dp[index][buy] = max(prices[index] + dp[index+2][1],
                                         0 + dp[index+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};