// Minimum Cost Path

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});
        
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty())
        {
            int curr_dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            pq.pop();
            
            for(auto a: dirs)
            {
                int ui = i + a[0];
                int uj = j + a[1];
                
                if(ui<n && ui >=0 && uj<n && uj>=0)
                {
                    if(curr_dist + grid[ui][uj] < dist[ui][uj])
                    {
                        dist[ui][uj] = curr_dist + grid[ui][uj];
                        pq.push({dist[ui][uj], {ui, uj}});
                    }
                    
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};