// Unique Paths III
class Solution {
public:
    int solve(vector<vector<int>>& grid, int count,int &maxCount, int x, int y)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1 || grid[x][y]==-2)
        {
            return 0;
        }
        if(grid[x][y]==2)
        {
            if(count-1==maxCount)
            {
                return 1;
            }
            return 0;
        }
        grid[x][y] = -2;
        int answer = 0;
        answer+=solve(grid, count+1, maxCount, x-1, y);
        answer+=solve(grid, count+1, maxCount, x+1, y);
        answer+=solve(grid, count+1, maxCount, x, y-1);
        answer+=solve(grid, count+1, maxCount, x, y+1);
        grid[x][y] = 0;
        return answer;
    }

    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int count=0;
        int x, y;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    count++;
                else if(grid[i][j]==1)
                {
                    x = i;
                    y = j;
                }
            }
        }

        return solve(grid, 0, count, x, y);
    }
};