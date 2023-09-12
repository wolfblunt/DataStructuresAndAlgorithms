// Longest Increasing Path in a Matrix - Using DP

class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int dfs(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp, int n, int m, int prev)
    {
        if(row < 0 || row >= n || col < 0 || col >= m || mat[row][col] <= prev)
        {
            return 0;
        }

        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int ans = 0;
        for(auto a: dirs)
        {
            int newRow = row + a[0];
            int newCol = col + a[1];
            ans = max(ans, 1+dfs(mat, newRow, newCol, dp, n, m, mat[row][col]));
        }

        return dp[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxx = max(maxx, dfs(mat, i, j, dp, n, m, -1));
            }
        }

        return maxx;
    }
};