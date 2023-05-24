// Distance of nearest cell having 1  - Using BFS

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int>(m,0));
	    vector<vector<int>> distance(n, vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                visited[i][j] = 1;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int dist = q.front().second;
	        q.pop();
	        for(auto a: dirs)
	        {
	            int newR = r + a[0];
	            int newC = c + a[1];
	            if(newR<n && newR>=0 && newC<m && newC>=0 && visited[newR][newC]==0)
	            {
	                q.push({{newR,newC}, dist+1});
	                visited[newR][newC] = 1;
	                distance[newR][newC] = dist+1;
	            }
	        }
	    }
	    
	    return distance;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}