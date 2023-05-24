// Number Of Enclaves

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& dirs, int r, int c, int n, int m)
    {
        visited[r][c] = 1;

        for(auto a:dirs)
        {
            int newR = r + a[0];
            int newC = c + a[1];
            if(newR >= 0 && newR < n && newC >= 0 && newC < m && !visited[newR][newC] && grid[newR][newC] == 1)
            {
                dfs(grid, visited, dirs, newR, newC, n, m);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> dirs = {{1,0}, {-1,0},{0,1},{0,-1}};
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && grid[i][0]==1)
            {
                dfs(grid, visited, dirs, i, 0, n, m);
            }

            if(!visited[i][m-1] && grid[i][m-1]==1)
            {
                dfs(grid, visited, dirs, i, m-1, n, m);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(!visited[0][j] && grid[0][j]==1)
            {
                dfs(grid, visited, dirs, 0, j, n, m);
            }

            if(!visited[n-1][j] && grid[n-1][j]==1)
            {
                dfs(grid, visited, dirs, n-1, j, n, m);
            }
        }

        int count = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}