// Climbing Stairs

class Solution {
public:
    int helper(int index, vector<int>& dp)
    {
        if(index==0)
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int oneStep = helper(index-1, dp);
        int twoStep = 0;
        if(index>1)
            twoStep = helper(index-2, dp);
        return dp[index]=oneStep+twoStep;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};