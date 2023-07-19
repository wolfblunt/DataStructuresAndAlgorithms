// Best Time to Buy and Sell Stock III - Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(n+1, vector<vector<int>>(2, vector<int>(3,0))));
        // dp[index][buy][capacity] => 1<=index<=n ; buy = 0 or 1 ; capacity = 0,1,2

        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0][0] = 0;
        //     dp[i][1][0] = 0;
        // }

        // for(int i=0;i<=1;i++)
        // {
        //     for(int j=0;j<=2;j++)
        //     {
        //         dp[0][i][j] = 0;
        //     }
        // }

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int capacity=1;capacity<=2;capacity++)
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

        return dp[0][1][2];
    }
};