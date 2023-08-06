// Matrix Chain Multiplication - Tabular : O(n^3)

int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n+1,0));

    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            int mini = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n];
}