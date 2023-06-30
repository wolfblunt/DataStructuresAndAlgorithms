// Last Day Where You Can Still Cross

class Solution {
public:
    bool isPossibleToCross(int n, int m, int index, vector<vector<int>>& cells)
    {
        vector<vector<int>> grid(n+1, vector<int>(m+1, 0));
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<index;i++)
        {
            grid[cells[i][0]][cells[i][1]] = 1;
        }

        queue<pair<int,int>> q;
        for(int i=1;i<=m;i++)
        {
            if(grid[1][i] == 0)
            {
                q.push({1,i});
                grid[1][i] = 1;
            }
        }

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(auto a: dirs)
            {
                int new_r = r + a[0];
                int new_c = c + a[1];
                if(new_r > 0 && new_r <=n && new_c > 0 && new_c <= m && grid[new_r][new_c]==0)
                {
                    grid[new_r][new_c] = 1;
                    if(new_r == n)
                    {
                        return true;
                    }
                    q.push({new_r, new_c});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high =  row*col;
        int latestDayPossible = 0;
        while(low < high-1)
        {
            int mid = low + (high-low)/2;
            if(isPossibleToCross(row, col, mid, cells))
            {
                low = mid;
                latestDayPossible = mid;
            }
            else
            {
                high = mid;
            }
        }
        return latestDayPossible;
    }
};