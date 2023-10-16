// Making A Large Island

class Solution {
public:
    int index = 2; // because 0 and 1 are already present
    
    void dfs(vector<vector<int>>& grid, int r, int c, int n, int &count)
    {
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c] > 1 || grid[r][c] == 0)
        {
            return;
        }
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        grid[r][c] = index;
        count++;
        for(auto a: dirs)
        {
            int nr = r + a[0];
            int nc = c + a[1];
            dfs(grid, nr, nc, n, count);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> um;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int countIsland = 0;
                    dfs(grid, i,j, n, countIsland);
                    um[index] = countIsland;
                    index++;
                }
            }
        }
        
        int maxIsland = INT_MIN;
        vector<vector<int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int sum = 0;
                    set<int> s;
                    for(auto a: dirs)
                    {
                        int nr = a[0] + i;
                        int nc = a[1] + j;
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] > 1 && s.find(grid[nr][nc]) == s.end())
                        {
                            auto curr = um[grid[nr][nc]];
                            sum += curr;
                            s.insert(grid[nr][nc]);
                        }
                    }
                    maxIsland = max(maxIsland, sum+1);
                }
            }
        }
        
        return maxIsland == INT_MIN? n*n : maxIsland;
    }
};