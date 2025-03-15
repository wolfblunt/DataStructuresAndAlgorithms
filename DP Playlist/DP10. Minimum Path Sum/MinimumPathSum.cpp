#include <bits/stdc++.h>
using namespace std;


int sumCalculate(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
    {
        return grid[i][j];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int up = grid[i][j] + sumCalculate(i-1,j,grid,dp);
    int left = grid[i][j] + sumCalculate(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return sumCalculate(n-1,m-1,grid,dp);
}


int main() 
{

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(matrix);
}