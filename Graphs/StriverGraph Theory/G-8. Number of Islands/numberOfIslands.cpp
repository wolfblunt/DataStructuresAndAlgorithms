// Number of Islands

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>> &dirs, int m, int n)
    {
        if(m<0 || m>=grid.size() || n<0 || n>=grid[0].size() || visited[m][n] || grid[m][n]=='0')
        {
            return;
        }
        visited[m][n] = 1;
        for(auto a: dirs)
        {
            dfs(grid, visited, dirs, m+a[0], n+a[1]);
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,1}, {-1,-1}, {1,-1}, {1,1}};
        int countIsland = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1' && visited[i][j]==0)
                {
                    countIsland+=1;
                    dfs(grid, visited, dirs, i, j);
                }
            }
        }
        return countIsland;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}