int recursiveUniquePaths(vector<vector<int>>& mat, vector<vector<int>>& dp, int m, int n)
{
    if(m>=0 && n>=0 && mat[m][n]==-1)
    {
        return 0;
    }
    if(m<0 || n<0)
    {
        return 0;
    }
    if(m==0 && n==0)
    {
        dp[m][n]=1;
        return 1;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    int up=0;
    int left=0;
    if(m>0)
        up = recursiveUniquePaths(mat, dp, m-1,n);
    if(n>0)
        left = recursiveUniquePaths(mat, dp, m, n-1);
    return dp[m][n]=((up+left)%1000000007); // for large values
}

int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    if(mat[m-1][n-1]==-1)
    {
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n,-1));
    recursiveUniquePaths(mat, dp, m-1, n-1);
    return dp[m-1][n-1];
}