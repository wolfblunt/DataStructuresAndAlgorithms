// Pacific Atlantic Water Flow

class Solution {
public:
    void helper(vector<vector<int>>& heights, int x, int y, int prev, vector<vector<int>>& ocean)
    {
        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size())
        {
            return;
        }
        if(ocean[x][y] == 1)
        {
            return;
        }
        if(heights[x][y] < prev)
        {
            return;
        }

        ocean[x][y] = 1;
        helper(heights, x+1, y, heights[x][y], ocean);
        helper(heights, x-1, y, heights[x][y], ocean);
        helper(heights, x, y+1, heights[x][y], ocean);
        helper(heights, x, y-1, heights[x][y], ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for(int i=0;i<n;i++)
        {
            helper(heights, i, 0, INT_MIN, pacific);
            helper(heights, i, m-1, INT_MIN, atlantic);
        }

        for(int j=0;j<m;j++)
        {
            helper(heights, 0, j, INT_MIN, pacific);
            helper(heights, n-1, j, INT_MIN, atlantic);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};