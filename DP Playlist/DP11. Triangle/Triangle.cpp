// https://leetcode.com/problems/triangle/description/
class Solution {
public:
    int pathSum(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp, int n)
    {
        if(i==n)
        {
            return triangle[n][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down = triangle[i][j] + pathSum(triangle, i+1, j, dp,n);
        int diagonal = triangle[i][j] + pathSum(triangle, i+1, j+1, dp,n);
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return pathSum(triangle, 0,0,dp, n-1);
    }
};