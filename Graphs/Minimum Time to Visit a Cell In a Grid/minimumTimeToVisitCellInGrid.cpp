// Minimum Time to Visit a Cell In a Grid - (m*nlog(m*n))

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;  // {time, {row, col}} minHeap

        pq.push({0, {0, 0}});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;

        vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1,0}, {-1,0}};

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int currTime = curr.first;
            int currRow = curr.second.first;
            int currCol = curr.second.second;

            if(currRow == n-1 && currCol == m-1)
            {
                return currTime;
            }

            for(auto a: dirs)
            {
                int nextRow = currRow + a.first;
                int nextCol = currCol + a.second;
                if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && !visited[nextRow][nextCol])
                {
                    int waitTime = abs(grid[nextRow][nextCol] - currTime) % 2 ? 0 : 1;
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);

                    pq.push({nextTime, {nextRow, nextCol}});
                    visited[nextRow][nextCol] = true;
                }
            }
        }

        return -1;
    }
};

