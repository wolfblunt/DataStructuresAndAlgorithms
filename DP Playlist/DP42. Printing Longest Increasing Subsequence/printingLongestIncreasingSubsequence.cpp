// Printing Longest Increasing Subsequence

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n,1);
	vector<int> hash(n);
	int maxi = 1;
	int lastIndex = 0;
	for(int i=0;i<n;i++)
	{
		hash[i] = i;
		for(int prev=0;prev<i;prev++)
		{
			if(arr[prev] < arr[i] && dp[i] < dp[prev]+1)
			{
				dp[i] = dp[prev] + 1;
				hash[i] = prev;
			}
		}
		if(maxi < dp[i])
		{
			maxi = dp[i];
			lastIndex = i;
		}
	}

	vector<int> lis;
	lis.push_back(arr[lastIndex]);
	while(hash[lastIndex] != lastIndex)
	{
		lastIndex = hash[lastIndex];
		lis.push_back(arr[lastIndex]);
	}

	reverse(lis.begin(), lis.end());
	return lis;
}
