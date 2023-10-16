// Shortest Distance in a Binary Maze

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> source = {0,0};
        pair<int, int> destination = {n-1,m-1};
        if(grid[0][0]==1)
        {
            return -1;
        }
        queue<pair<int, pair<int, int>>> q; // queue<distance, <row, col>>
        q.push({1,{0,0}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        vector<vector<int>> t = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int dr = destination.first;
        int dc = destination.second;
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            int d = a.first;
            int r = a.second.first;
            int c = a.second.second;
            
            if(dr == r && dc == c)
            {
                return d;
            }
            for(auto b: t)
            {
                int nr = r + b[0];
                int nc = c + b[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && d+1 < dis[nr][nc])
                {
                    dis[nr][nc] = d + 1;
                    q.push({d+1, {nr, nc}});
                }
            }
        }
        
        return -1;
    }
};