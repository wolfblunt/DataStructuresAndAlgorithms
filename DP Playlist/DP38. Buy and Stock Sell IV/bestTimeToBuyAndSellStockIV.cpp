// Best Time to Buy and Sell Stock IV - Memoization

class Solution {
public:
    int helper(vector<int>& prices, int index, int buy, int capacity, vector<vector<vector<int>>> &dp)
    {
        if(capacity == 0)
        {
            return 0;
        }
        if(index == prices.size())
        {
            return 0;
        }
        if(dp[index][buy][capacity] != -1)
        {
            return dp[index][buy][capacity];
        }

        if(buy)
        {
            return dp[index][buy][capacity] = max(-prices[index] + helper(prices, index+1, 0, capacity, dp),
                                                  0 + helper(prices, index+1, 1, capacity, dp));
        }

        return dp[index][buy][capacity] = max(prices[index] + helper(prices, index+1, 1, capacity-1, dp),
                                               0 + helper(prices, index+1, 0, capacity, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return helper(prices, 0, 1, k, dp);
    }
};