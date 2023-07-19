// Best Time to Buy and Sell Stock with Cooldown - Space Optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead1(2,0), curr(2,0), ahead2(2,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    curr[buy] = max(-prices[index] + ahead1[0],
                                         0 + ahead1[1]);
                }
                else
                {
                    curr[buy] = max(prices[index] + ahead2[1],
                                         0 + ahead1[0]);
                }
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }

        return curr[1];
    }
};