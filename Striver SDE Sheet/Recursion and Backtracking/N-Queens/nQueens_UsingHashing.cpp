// N-Queens - Using Hashing

class Solution {
public:
    void solve(int column, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> leftRow, vector<int> upperDiagonal, vector<int> lowerDiagonal)
    {
        if(column == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++)
        {
            if(leftRow[row] == 0 && lowerDiagonal[row + column] == 0 && upperDiagonal[n - 1 + column - row] == 0)
            {
                board[row][column] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + column] = 1;
                upperDiagonal[n -1 + column - row] = 1;
                solve(column+1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
                board[row][column] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + column] = 0;
                upperDiagonal[n -1 + column - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};