// Best Time to Buy and Sell Stock II - Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));  // 1 for buy and 2 for sell
        vector<int> ahead(2,0), curr(2,0);
        ahead[1] = 0;
        ahead[0] = 0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max(-prices[index] + ahead[0], // buy the stock
                                                0 + ahead[1]); // not buy the stock
                }

                // for selling the stock if buy == 0
                else
                {
                    profit = max(prices[index] + ahead[1], // sell the stock
                                                0 + ahead[0]); // not sell the stock
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};