// Score After Flipping Matrix

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();

        int mScore = (1 << (m-1)) * n;

        for(int j=1;j<m;j++)
        {
            int ColMagnitude = 1 << (m-1-j);
            int setBits = 0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j] == grid[i][0])
                {
                    setBits++;
                }
            }

            mScore += max(setBits, n-setBits) * ColMagnitude;
        }

        return mScore;
    }
};