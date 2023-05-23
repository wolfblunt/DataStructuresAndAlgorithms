// Shortest Bridge

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& dirs, queue<pair<int,int>>& q, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j])
        {
            return;
        }

        visited[i][j] = true;
        q.push({i,j});
        for(auto& a: dirs)
        {
            dfs(grid, visited, dirs, q, i+a[0], j+a[1]);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        bool found = false;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid, visited, dirs, q, i, j);
                    found = true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }

        // BFS
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size-- > 0)
            {
                auto curr = q.front();
                q.pop();
                for(auto& a: dirs)
                {
                    int i = curr.first + a[0];
                    int j = curr.second + a[1];
                    if(i>=0 && j>=0 && i<n && j<m && !visited[i][j])
                    {
                        if(grid[i][j] == 1)
                        {
                            return step;
                        }
                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};