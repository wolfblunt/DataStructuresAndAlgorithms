// Minimum Moves to Spread Stones Over Grid

class Solution {
public:
    int helper(vector<vector<int>>& grid)
    {
        bool check = true;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j] != 1)
                {
                    check = false;
                    break;
                }
            }
        }

        if(check)
        {
            return 0;
        }

        int countMoves = 1e9;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(grid[i][j] == 0 && grid[k][l] > 1)
                        {
                            grid[k][l] -= 1;
                            grid[i][j] += 1;
                            int dist = abs(i-k) + abs(j-l);
                            countMoves = min(countMoves, dist + helper(grid));
                            grid[k][l] += 1;
                            grid[i][j] -= 1;
                        }
                    }
                }
            }
        }

        return countMoves;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        return helper(grid);
    }
};