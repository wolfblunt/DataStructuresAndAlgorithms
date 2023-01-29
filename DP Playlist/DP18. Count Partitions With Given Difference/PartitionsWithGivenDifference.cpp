#include <bits/stdc++.h> 
int mod = (int)1e9+7;
int totalWays(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(target==0 && arr[index]==0)
        {
            return 2;
        }
        if(target==0 || arr[index]==target)
        {
            return 1;
        }
        return 0;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    int notPick = totalWays(arr, index-1, target, dp);
    int pick = 0;
    if(arr[index] <= target)
    {
        pick = totalWays(arr, index-1, target-arr[index], dp);
    }
    return dp[index][target] = (pick+notPick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(auto a: arr)
    {
        totalSum += a;
    }
    if(totalSum -d < 0 || (totalSum - d)%2)
    {
        return false;
    }
    int target = (totalSum-d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return totalWays(arr, n-1, target, dp);
}