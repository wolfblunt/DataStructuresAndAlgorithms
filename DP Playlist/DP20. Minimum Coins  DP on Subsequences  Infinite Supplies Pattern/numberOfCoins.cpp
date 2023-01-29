class Solution {
public:
    int helper(vector<int>& coins, int index, int amount, vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(amount%coins[index]==0)
                return amount/coins[index];
            else
                return 1e9;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        int notPick = 0 + helper(coins, index-1, amount, dp);
        int pick = 1e9;
        if(amount>=coins[index])
        {
            pick = 1 + helper(coins, index, amount-coins[index], dp);
        }
        return dp[index][amount]=min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int n = helper(coins, coins.size()-1, amount, dp);
        if(n>=1e9)
            return -1;
        return n;
    }
};