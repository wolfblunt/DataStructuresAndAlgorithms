// Game of Life - O(8*n*m + n*m)

class Solution {
public:
    int helper(vector<vector<int>>& board, int r, int c)
    {
        vector<pair<int, int>> dirs = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
        int liveNeighbors = 0;
        int n = board.size();
        int m = board[0].size();
        for(auto a: dirs)
        {
            int nr = r + a.first;
            int nc = c + a.second;

            if(nr>=0 && nr<n && nc>=0 && nc<m && (board[nr][nc] == 1 || board[nr][nc] == 2))
            {
                liveNeighbors++;
            }
        }

        return liveNeighbors;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        // 3: dead -> live
        // 2: live -> dead
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int liveNeighbors = helper(board, i, j);
                if(board[i][j] == 1)
                {
                    if(liveNeighbors < 2 || liveNeighbors > 3) // live -> dead
                    {
                        board[i][j] = 2;
                    }
                }
                else
                {
                    if(liveNeighbors == 3) // dead -> live
                    {
                        board[i][j] = 3;
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 2)
                {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};