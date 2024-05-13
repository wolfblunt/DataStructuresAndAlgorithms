// Largest Local Values in a Matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size();
        vector<vector<int>> answer(n-2, vector<int>(n-2));

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                int maxVal = 0;

                for(int k=i-1;k<=i+1;k++)
                {
                    for(int l=j-1;l<=j+1;l++)
                    {
                        maxVal = max(maxVal, grid[k][l]);
                    }
                }

                answer[i-1][j-1] = maxVal;
            }
        }

        return answer;
    }
};