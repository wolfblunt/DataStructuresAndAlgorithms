// Matrix Chain Multiplication

int helper(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if(i==j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int cost = arr[i-1]*arr[k]*arr[j] + helper(arr, i, k, dp) + helper(arr, k+1,j,dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return helper(arr, 1, N-1, dp);
}