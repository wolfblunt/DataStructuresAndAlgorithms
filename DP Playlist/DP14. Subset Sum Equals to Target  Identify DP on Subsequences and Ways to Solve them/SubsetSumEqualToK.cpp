#include <bits/stdc++.h> 

bool helperFunc(int index, int k, vector<int> &arr,  vector<vector<int>> &dp)
{
    if(k==0)
    {
        return true;
    }
    if(index==0)
    {
        return arr[index]==k;
    }
    if(dp[index][k]!=-1)
    {
        return dp[index][k];
    }
    bool notPick = helperFunc(index-1, k, arr, dp);
    bool pick = false;
    if(arr[index]<=k)
    {
        pick = helperFunc(index-1, k-arr[index], arr,dp);
    }
    return dp[index][k] = pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return helperFunc(n-1,k, arr, dp);
}