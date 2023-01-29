// Minimum Falling Path Sum

class Solution {
public:
    int dpFallingPathSum(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &dp)
    {
        if(row==0 && col>=0 && col<matrix[0].size())
        {
            return dp[row][col] = matrix[row][col];
        }
        if(col<0 || col>=matrix[0].size())
        {
            return INT_MAX;
        }
        if(dp[row][col]!=INT_MAX)
        {
            return dp[row][col];
        }
        int result = INT_MAX;
        result = min(result, dpFallingPathSum(matrix, row-1, col-1, dp));
        result = min(result, dpFallingPathSum(matrix, row-1, col, dp));
        result = min(result, dpFallingPathSum(matrix, row-1, col+1, dp));
        return dp[row][col]=result+matrix[row][col];
    }    

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1,INT_MAX));
        int result = INT_MAX;
        for(int i=0;i<cols;i++)
        {
            result = min(result, dpFallingPathSum(matrix, rows-1, i, dp));
        }   
        return result; 
    }
};