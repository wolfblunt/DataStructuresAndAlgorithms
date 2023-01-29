// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
#include <bits/stdc++.h> 
bool subsetSumToK(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if(target==0)
    {
        dp[index][target] = 1;
        return true;
    }
    if(index==0)
    {
        return dp[index][target] = arr[index]==target;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    bool notPick = subsetSumToK(arr, index-1, target, dp);
    bool pick = false;
    if(arr[index]<=target){
        pick = subsetSumToK(arr, index-1, target-arr[index], dp);
    }
    return dp[index][target] = pick | notPick;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    for(int i=0;i<=sum;i++)
    {
        bool dummy = subsetSumToK(arr, n-1, i, dp);
    }

    int minimum = 1e9;
    for(int i=0;i<=sum/2;i++)
    {
        if(dp[n-1][i]==true)
        {
            int secondSum = sum - i;
            int minDiff = abs(i-secondSum);
            minimum = min(minimum, minDiff);
        }
    }
    return minimum;
}