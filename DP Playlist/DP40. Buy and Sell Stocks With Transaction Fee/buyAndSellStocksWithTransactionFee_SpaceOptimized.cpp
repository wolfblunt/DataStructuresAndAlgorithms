// Buy and Sell Stocks With Transaction Fee - Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        vector<int> ahead(2,0), curr(2,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    curr[buy] = max(-prices[index] - fee + ahead[0],
                                         0 + ahead[1]);
                }
                else
                {
                   curr[buy] = max(prices[index] + ahead[1],
                                         0 + ahead[0]);
                }
            }
            ahead = curr;
        }

        return ahead[1];
    }
};