// Difference of Number of Distinct Values on Diagonals

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                int x = i+1;
                int y = j+1;
                unordered_set<int> s1;
                while(x<grid.size() && y<grid[0].size())
                {
                    s1.insert(grid[x][y]);
                    x++;
                    y++;
                }
                
                x = i-1;
                y = j-1;
                unordered_set<int> s2;
                while(x>=0 && y>=0)
                {
                    s2.insert(grid[x][y]);
                    x--;
                    y--;
                }
                
                ans[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        
        return ans;
    }
};