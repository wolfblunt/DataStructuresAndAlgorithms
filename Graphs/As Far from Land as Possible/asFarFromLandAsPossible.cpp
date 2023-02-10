// As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }

        if(q.size()==0 || q.size()==grid.size()*grid[0].size())
        {
            return -1;
        }
        vector<vector<int>> visited = grid;
        int level = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(q.size()>0)
        {
            level++;
            int size = q.size();
            while(size--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        return level;
    }
};