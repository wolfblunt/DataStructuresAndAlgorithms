// Geeks Island

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool valid(int i, int j, vector<vector<bool>> &vis, int prev, vector<vector<int>> &mat)
    {
        int n = vis.size(), m = vis[0].size();
        return i >=0 && j >= 0 && i < n && j < m && !vis[i][j] && prev <= mat[i][j];
    }
    
    int water_flow(vector<vector<int>> &mat,int n,int m)
    {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<m;i++)
        {
            q.push({0,i});
            visited[0][i] = true;
        }
        
        for(int i=0;i<n;i++)
        {
            q.push({i,0});
            visited[i][0] = true;
        }
        map<pair<int, int>, int> indianOcean;
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();
            indianOcean[{i,j}]=true;
            visited[i][j] = true;
            if(valid(i+1, j, visited, mat[i][j], mat))
            {
                visited[i+1][j] = 1;
                q.push({i+1,j});
            }
            
            if(valid(i-1, j, visited, mat[i][j], mat))
            {
                visited[i-1][j] = 1;
                q.push({i-1,j});
            }
            
            if(valid(i, j-1, visited, mat[i][j], mat))
            {
                visited[i][j-1] = 1;
                q.push({i,j-1});
            }
            
            if(valid(i, j+1, visited, mat[i][j], mat))
            {
                visited[i][j+1] = 1;
                q.push({i,j+1});
            }
        }
        
        vector<vector<bool>> vi(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++)
        {
            q.push({i, m-1});
            vi[i][m-1] = true;
        }
        for(int j = 0; j < m-1; j++)
        {
            q.push({n-1, j});
            vi[n-1][j] = 1;
        }
        
        int cnt = 0;
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            int i = p.first, j = p.second;
            q.pop();
            if(indianOcean[{i, j}]) {cnt++;}
            vi[i][j] = true;
            if(valid(i+1, j, vi, mat[i][j], mat)){
                vi[i+1][j] = true;
                q.push({i+1, j});
            }
            if(valid(i-1, j, vi, mat[i][j], mat)){
                vi[i-1][j] = 1;
                q.push({i-1, j});
            }
            if(valid(i, j-1, vi, mat[i][j], mat)){
                vi[i][j-1] = 1;
                q.push({i, j-1});
            }
            if(valid(i, j+1, vi,mat[i][j], mat)){
                vi[i][j+1] = 1;
                q.push({i, j+1});
            }
        }
        return cnt;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}