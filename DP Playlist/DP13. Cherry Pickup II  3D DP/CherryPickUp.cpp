#include <bits/stdc++.h> 

int functionPickUp(vector<vector<int>> &grid, int i, int j1, int j2, int r, int c, vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>c || j2<0 || j2>c)
    {
        return -1e8;
    }
    if(i==r)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e8;
    
    // explore all paths of Alice and Bob simultaneously
    for(int d1=-1; d1<=1; d1++)
    {
        for(int d2=-1; d2<=1; d2++)
        {
            int value = 0;
            if(j1==j2)
            {
                value = grid[i][j1] + functionPickUp(grid, i+1,j1+d1, j2+d2, r, c, dp);
            }
            else
            {
                value = grid[i][j1] + grid[i][j2] + functionPickUp(grid, i+1,j1+d1, j2+d2, r, c, dp);
            }
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // int dp[r][c][c]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return functionPickUp(grid, 0,0,c-1,r-1,c-1,dp);
}