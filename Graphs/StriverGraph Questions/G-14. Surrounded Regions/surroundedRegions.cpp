// Surrounded Regions

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    void dfs(vector<vector<char>> &mat, vector<vector<int>> &visited, int r, int c, vector<vector<int>> &dirs, int n, int m)
    {
        visited[r][c] = 1;
        for(auto a: dirs)
        {
            int newR = r + a[0];
            int newC = c + a[1];
            if(newR >= 0 && newR <n && newC >= 0 && newC < m && !visited[newR][newC] && mat[newR][newC] == 'O')
            {
                dfs(mat, visited, newR, newC, dirs, n, m);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && mat[i][0]=='O')
            {
                dfs(mat, visited, i, 0, dirs, n, m);
            }
            
            if(!visited[i][m-1] && mat[i][m-1]=='O')
            {
                dfs(mat, visited, i, m-1, dirs, n, m);
            }
        }
        
        for(int j=0;j<m;j++)
        {
            if(!visited[0][j] && mat[0][j]=='O')
            {
                dfs(mat, visited, 0, j, dirs, n, m);
            }
            
            if(!visited[n-1][j] && mat[n-1][j]=='O')
            {
                dfs(mat, visited, n-1, j, dirs, n, m);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && mat[i][j]=='O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}