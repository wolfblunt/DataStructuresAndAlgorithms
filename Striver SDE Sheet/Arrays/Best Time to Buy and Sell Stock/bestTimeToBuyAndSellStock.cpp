// Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestStockBuy=INT_MAX; 
        int ifSellToday=0;  // profit if sold today
        int profit=0;  // overall profit
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i] < lowestStockBuy) // if we found new buy value which is more smaller then previous one
            {
                lowestStockBuy = prices[i];
            }
            ifSellToday = prices[i] - lowestStockBuy;  // calculating profit if sold today by, Buy - sell
            if(profit < ifSellToday)  // if pist is more then our previous overall profit
            {
                profit = ifSellToday;
            }
        }
        return profit;
    }
};