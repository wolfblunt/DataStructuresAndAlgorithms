// Maximum sum of non-adjacent elements - O(n)

#include <bits/stdc++.h> 
int helper(vector<int>& arr, int index, vector<int>& dp)
{
    if(index == 0)
        return arr[index];
    
    if(index < 0)
        return 0;
        
    if(dp[index]!=-1)
        return dp[index];
        
    int pick = arr[index] + helper(arr, index-2, dp);
    int notPick = 0 + helper(arr, index-1, dp);
    
    return dp[index] = max(pick, notPick);    
}

int maximumNonAdjacentSum(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, -1);
    return helper(arr, n-1, dp);
}