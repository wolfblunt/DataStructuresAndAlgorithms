// Unique Paths in a Grid

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findWays(vector<vector<int>> &grid,vector<vector<int>> &dp ,int n, int m)
    {
        if(n>=0 && m>=0 && grid[n][m]==0)
        {
            return 0;
        }
        
        if(n<0 || m<0)
        {
            return 0;
        }
        
        if(n==0 && m==0)
        {
            return dp[n][m]=1;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        int up = 0;
        int left = 0;
        if(n>0)
            up = findWays(grid, dp, n-1, m);
        if(m>0)
            left = findWays(grid, dp, n, m-1);;
        return dp[n][m] = ((up+left)%1000000007);
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[n-1][m-1]==0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return findWays(grid, dp, n-1, m-1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}