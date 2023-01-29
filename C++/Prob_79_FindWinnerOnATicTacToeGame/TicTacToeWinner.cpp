// Find Winner on a Tic Tac Toe Game
class Solution {
public:
    bool ticTacToeHelper(vector<vector<int>> &grid, int i, int j)
    {
        int count=0;
        for(int k=0;k<3;k++)
        {
            count+=grid[k][j];
        }
        if(abs(count)==3)
        {
            return true;
        }
        count = 0;
        for(int k=0;k<3;k++)
        {
            count+=grid[i][k];
        }
        if(abs(count)==3)
        {
            return true;
        }
    
        count = 0;
        if(i==j)
        {
            count = grid[0][0]+grid[1][1]+grid[2][2];
            if(abs(count)==3)
            {
                return true;
            }
        }
        count = 0;
        if(i+j==2)
        {
            count = grid[0][2]+grid[1][1]+grid[2][0];
            if(abs(count)==3)
            {
                return true;
            }
        }
        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int>> grid(3, vector<int>(3,0));
        for(int k=0;k<n;k++)
        {
            int i = moves[k][0];
            int j = moves[k][1];
            if(k%2==0)
            {
                grid[i][j]=1;
                if(ticTacToeHelper(grid, i, j))
                {
                    return "A";
                }
            }
            else
            {
                grid[i][j] = -1;
                if(ticTacToeHelper(grid, i, j))
                {
                    return "B";
                }
            }
        }
        if(n>=9)
        {
            return "Draw";
        }
        
        return "Pending";
        }
};