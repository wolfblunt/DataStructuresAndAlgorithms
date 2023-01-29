// Snakes and Ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        vector<int> flattenBoard(n*n);
        int index = 0;
        int leftToRightFlag = 1;
        for(int i = n-1; i>=0; i--)
        {
            if(leftToRightFlag)
            {
                for(int j=0;j<n;j++)
                {
                    flattenBoard[index] = board[i][j];
                    index++;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    flattenBoard[index] = board[i][j];
                    index++;
                }
            }
            leftToRightFlag = !leftToRightFlag;
        }

        queue<int> q;
        vector<int> dist(n*n, -1);
        q.push(0);
        dist[0] = 0;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            if(current == n*n-1)
            {
                return dist[current];
            }
            for(int i=1;i<=6;i++)
            {
                int next = current+i;
                if(next >= n*n)
                {
                    continue;
                }
                if(flattenBoard[next]!=-1)
                {
                    next = flattenBoard[next] - 1;
                }
                if(dist[next]==-1)
                {
                    dist[next] = dist[current] + 1;
                    q.push(next);
                }
            }
        }

        return -1;    
    }
};