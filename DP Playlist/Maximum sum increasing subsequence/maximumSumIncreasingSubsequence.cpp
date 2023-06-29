// Maximum sum increasing subsequence

#include <bits/stdc++.h> 
int helper(vector<int> &arr, int index, int prevIndex, vector<vector<int>> &dp, int n)
{
	if(index == n)
	{
		return 0;
	}
	if(dp[index][prevIndex+1]!=-1)
	{
		return dp[index][prevIndex+1];
	}
	int notPick = 0 + helper(arr, index+1, prevIndex, dp, n);
	int pick = INT_MIN;
	if(prevIndex == -1 || arr[index] > arr[prevIndex])
	{
		pick = arr[index] + helper(arr, index+1, index, dp, n);
	}
	
	return dp[index][prevIndex+1] = max(pick, notPick);
}

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	return helper(arr, 0, -1, dp, n);
}