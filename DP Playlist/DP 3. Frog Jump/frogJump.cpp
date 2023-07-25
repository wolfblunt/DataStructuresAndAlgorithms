// Frog Jump

#include <bits/stdc++.h> 

int helper(vector<int> &heights, vector<int> &dp, int index)
{
    if(index == 0)
    {
        return 0;
    }

    if(dp[index]!=-1)
    {
        return dp[index];
    }

    int oneStep = abs(heights[index] - heights[index-1]) + helper(heights, dp, index-1);
    int twoSteps = INT_MAX;
    if(index-2 >=0)
    {
        twoSteps = abs(heights[index] - heights[index-2]) + helper(heights, dp, index-2);
    }

    return dp[index] = min(oneStep, twoSteps);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return helper(heights, dp, n-1);
}