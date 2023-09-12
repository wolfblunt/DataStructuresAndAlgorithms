// Longest Increasing Path in a Matrix - Using DFS

class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp, int n, int m)
    {
        for(auto a: dirs)
        {
            int newRow = row + a[0];
            int newCol = col + a[1];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[row][col] < mat[newRow][newCol])
            {
                dp[newRow][newCol] = max(dp[newRow][newCol], dp[row][col] + 1);
                dfs(mat, newRow, newCol, dp, n, m);
            }
        }   
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dfs(mat, i, j, dp, n, m);
            }
        }

        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxx = max(maxx, dp[i][j]);
            }
        }

        return maxx;
    }
};