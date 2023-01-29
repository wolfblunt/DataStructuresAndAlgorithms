// Coin Change II

class Solution {
public:
    int helper(int amount, int index, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(amount%coins[index]==0)
            {
                return dp[index][amount]=1;
            }
            else
            {
                return dp[index][amount]=0;
            }
        }
        
        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }

        int notPick = 0 + helper(amount, index-1, coins, dp);
        int pick = 0;
        if(amount>=coins[index])
        {
            pick = helper(amount-coins[index], index, coins, dp);
        }
        return dp[index][amount]=pick+notPick;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return helper(amount, coins.size()-1, coins, dp);
    }
};
