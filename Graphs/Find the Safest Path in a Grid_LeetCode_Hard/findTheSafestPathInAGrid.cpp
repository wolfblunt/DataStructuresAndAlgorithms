// Find the Safest Path in a Grid

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    // ------------------------------- DFS --------------------------------------------
    bool dfs(vector<vector<int>> &grid, int i, int j, int r, int c, int val, vector<vector<bool>> &visited)
    {
        if(i<0  || i>=r || j<0 || j>=c || visited[i][j])
        {
            return false;
        }

        if(i==r-1 && j==c-1)
        {
            return grid[i][j] >= val;
        }

        visited[i][j] = true;

        for(auto a: dirs)
        {
            int newR = i + a.first;
            int newC = j + a.second;
            if(grid[i][j] >= val)
            {
                if(dfs(grid, newR, newC, r, c, val, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        if(grid[0][0] == 1 || grid[r-1][c-1] == 1)
        {
            return 0;
        }

        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                }
            }
        }
        // ------------------------- BFS -----------------------------
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int value = grid[row][col];
            
            for(auto a: dirs)
            {
                int newR = row + a.first;
                int newC = col + a.second;

                if(newR>=0 && newR<r && newC>=0 && newC<c && grid[newR][newC]==0)
                {
                    grid[newR][newC] = value+1;
                    q.push({newR, newC});
                }
                else if(newR>=0 && newR<r && newC>=0 && newC<c)
                {
                    grid[newR][newC] = min(grid[newR][newC], value+1);
                }
            }
        }

        // ---------------------------------------------------------------

        // ----------------- Binary Search -------------------------------

        int ans = 0;
        int low = 0;
        int high = 400;
        while(low<=high)
        {
            int mid = (low+high)/2;
            vector<vector<bool>> visited(r, vector<bool>(c, false));
            if(dfs(grid, 0, 0, r, c, mid, visited))
            {
                ans = max(ans, mid);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return ans-1;
    }
};