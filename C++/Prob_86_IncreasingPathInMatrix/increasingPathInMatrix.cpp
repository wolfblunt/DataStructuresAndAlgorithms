#include <bits/stdc++.h> 

int gridPath(vector<vector<int>> &mat,int i, int j ,int n, int m, vector<vector<int>> &dp)
{
    if(i==n-1 && j==m-1)
        return dp[i][j]=1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int result = 0;
    if(i!=n-1)
    {
        if(mat[i][j]<mat[i+1][j])
            result = gridPath(mat, i+1, j , n, m, dp) + 1;
        else
            result=1;
    }
    if(j!=m-1)
    {
        if(mat[i][j]<mat[i][j+1])
        {
            result = max(result,gridPath(mat, i, j+1 , n, m, dp) + 1);
        }
        else
            result=max(1,result);
    }
    return dp[i][j]=result;
}

int longestIncreasingPath(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return gridPath(mat, 0,0, n, m, dp);
}

// Input
// 5        -> No of test cases
// 8 1      -> 1st test case matri dim
// 4
// -4
// 4
// -3
// -10
// -8
// 7
// 1
// 3 4
// -9 0 -7 10
// 8 4 -10 7
// -10 8 -10 1
// 1 7
// 5 -2 2 0 0 10 3
// 3 7
// -1 -3 3 -4 -5 -2 1
// 0 -9 6 7 -9 -5 -4
// 0 -1 0 2 2 -10 4
// 1 9
// -2 2 4 7 -5 4 6 8 -5


// Output
// 1
// 4
// 1
// 2
// 4