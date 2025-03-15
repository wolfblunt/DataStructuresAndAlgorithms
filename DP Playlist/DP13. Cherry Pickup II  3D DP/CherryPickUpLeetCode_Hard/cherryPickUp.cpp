// https://leetcode.com/problems/cherry-pickup/description/
class Solution {
public:
    int cherryFunc(vector<vector<int>>& grid, int i, int j1, int j2, int r, vector<vector<vector<int>>>& dp)
    {
        int i2 = i+j1-j2;
        if(i>r || i2>r || j1>r || j2>r || grid[i][j1]==-1 || grid[i2][j2]==-1)
        {
            return -1e8;
        }
        if(i==r && j1==r)
        {
            return grid[i][j1];
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int value = grid[i][j1];
        if(j1!=j2)
        {
            value += grid[i2][j2];
        }
        // 4 possibilities
        // {r1=i1,r2=i2,c1=j1+1,c2=j2+1} , {r1=i1,r2=i2+1,c1=j1+1,c2=j2}, {r1=i1+1,r2=i2,c1=j1,c2=j2+1}, {r1=i1+1,r2=i2+1,c1=j1,c2=j2}
        value += max(cherryFunc(grid, i, j1+1, j2+1, r, dp), max(cherryFunc(grid, i, j1+1, j2, r, dp), max(cherryFunc(grid, i+1, j1, j2+1, r, dp), cherryFunc(grid, i+1, j1, j2, r, dp))));
        return dp[i][j1][j2] = value;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));  // dp[r][c1][c2]
        return max(0, cherryFunc(grid, 0, 0, 0, n-1, dp));
    }
};