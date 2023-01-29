// Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int n = matrix.size();
        int col = matrix[0].size()-1;
        while(row<n && col>=0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return false;
    }
};