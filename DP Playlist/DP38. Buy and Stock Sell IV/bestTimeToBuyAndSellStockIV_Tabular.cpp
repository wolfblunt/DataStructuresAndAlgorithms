// Best Time to Buy and Sell Stock IV - Tabular

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int capacity=1;capacity<=k;capacity++)
                {
                    if(buy)
                    {
                        dp[index][buy][capacity] = max(-prices[index] + dp[index+1][0][capacity],
                                                            0 + dp[index+1][1][capacity]);
                    }
                    else
                    {
                        dp[index][buy][capacity] = max(prices[index] + dp[index+1][1][capacity-1],
                                                            0 + dp[index+1][0][capacity]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};