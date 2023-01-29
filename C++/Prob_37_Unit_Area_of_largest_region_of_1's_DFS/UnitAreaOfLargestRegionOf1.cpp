//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int largestArea(vector<vector<int>>& grid, int i, int j, int n, int m)  // Using DFS
    {
        if(i<0 || j<0 || i> n-1 || j>m-1 || grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j]=0;
        int ways = 1;
        ways += largestArea(grid, i+1, j, n, m);
        ways += largestArea(grid, i+1, j-1, n, m);
        ways += largestArea(grid, i+1, j+1, n, m);
        ways += largestArea(grid, i, j-1, n, m);
        ways += largestArea(grid, i, j+1, n, m);
        ways += largestArea(grid, i-1, j-1, n, m);
        ways += largestArea(grid, i-1, j, n, m);
        ways += largestArea(grid, i-1, j+1, n, m);
        return ways;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ways=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ways = max(ways, largestArea(grid,i,j,n,m));
                }
            }
        }
        return ways;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends