// Rotten Oranges

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        // BFS
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int time = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(auto a: dirs)
            {
                int nrow = r + a[0];
                int ncol = c + a[1];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol}, t+1});
                    visited[nrow][ncol] = true;
                }
            }
        }

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]==1) // Checking if any of orange are left unrotten or not
                    return -1;
            }
        }

        return time;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}