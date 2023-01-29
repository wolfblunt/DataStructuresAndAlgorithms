// Set Matrix Zeroes
// Time - O(row*col) + O(row*col)
// Space - O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<r;i++)
        {
            if(matrix[i][0] == 0)
            {
                col0 = 0;
            }
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=1;j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};