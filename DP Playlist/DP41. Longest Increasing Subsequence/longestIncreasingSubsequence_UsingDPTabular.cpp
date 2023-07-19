// Longest Increasing Subsequence - Using DP Tabular

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int index=n-1;index>=0;index--)
    {
        for(int prevIndex=index-1;prevIndex>=-1;prevIndex--)
        {
            int len = 0 + dp[index+1][prevIndex+1];
            if(prevIndex==-1 || arr[index] > arr[prevIndex])
            {
                len = max(len, 1 + dp[index+1][index+1]);
            }
            dp[index][prevIndex+1] = len;
        }
    }
    return dp[0][-1+1];
}