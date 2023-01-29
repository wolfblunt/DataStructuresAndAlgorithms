// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
#include <bits/stdc++.h> 

int maxSum(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int m)
{
    if(j<0 || j>=m)
    {
        return -1e8;
    }
    if(i==0)
    {
        return matrix[0][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int u = matrix[i][j] + maxSum(matrix, dp, i-1, j, m);
    int ld = matrix[i][j] + maxSum(matrix, dp, i-1, j-1, m);
    int rd = matrix[i][j] + maxSum(matrix, dp, i-1, j+1, m);
    return dp[i][j] = max(u,max(ld,rd));
}
    
    
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    int maxi = -1e8;
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi, maxSum(matrix, dp, n-1, j, m));
    }
    return maxi;
}