// Number of Distinct Islands  -- O(n*m*log(n*m)) + O(n*m*4)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int,int>> &v, int r, int c, int baseRow, int baseCol)
    {
        visited[r][c] = 1;
        v.push_back({r-baseRow, c-baseCol});
        
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(auto a: dirs)
        {
            int newR = r+a[0];
            int newC = c+a[1];
            if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && !visited[newR][newC] && grid[newR][newC]==1)
            {
                dfs(grid, visited, v, newR, newC, baseRow, baseCol);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        set<vector<pair<int,int>>> s;  // O(n*m*log(n*m))

        // O(n*m*4)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> v;
                    dfs(grid, visited, v, i,j,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}