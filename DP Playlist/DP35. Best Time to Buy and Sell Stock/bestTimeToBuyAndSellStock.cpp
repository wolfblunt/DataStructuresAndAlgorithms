// Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++)
        {
            int p = prices[i] - mini;
            profit = max(profit, p);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};