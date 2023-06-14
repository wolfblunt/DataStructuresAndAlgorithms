// Sudoku Solver

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char no)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == no)
            {
                return false;
            }

            if(board[row][i] == no)
            {
                return false;
            }

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == no)
            {
                return false;
            }
        }
        return true;
    }

    bool completeSudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if(completeSudoku(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        completeSudoku(board);
    }
};