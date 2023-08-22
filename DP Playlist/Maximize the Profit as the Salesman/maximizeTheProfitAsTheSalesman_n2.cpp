// Maximize the Profit as the Salesman - O(n2)

class Solution {
public:
    int helper(vector<vector<int>>& offers, int prev, int index, vector<vector<int>>& dp)
    {
        if(index == offers.size())
        {
            return 0;
        }

        if(dp[index][prev+1] != -1)
        {
            return dp[index][prev+1];
        }

        int notTake = helper(offers, prev, index+1, dp);
        int take = 0;
        if(prev == -1 || offers[prev][1] < offers[index][0])
        {
            take = offers[index][2] + helper(offers, index, index+1, dp);
        }

        return dp[index][prev+1] = max(take, notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        int m = offers.size();
        vector<vector<int>> dp(m, vector<int>(m+1,-1));
        return helper(offers, -1, 0, dp);
    }
};