//Iterative bottom-up solution
class Solution {
public:
    int customMin(int a, int b, int c){
        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = INT_MAX;
        
        for(int r=1; r < rows; r++){
            for(int c=0; c < cols; c++){
                int leftD, middle, rightD;               
                if(c == 0){
                    rightD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(rightD, middle);
                }else if(c == cols-1){
                    leftD = matrix[r-1][c-1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(leftD, middle);
                }else{
                    leftD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    rightD = matrix[r-1][c-1];
                    matrix[r][c] += customMin(leftD, rightD, middle);
                } 
            }
        }
        for(int c=0; c < cols; c++){
            ans = min(ans, matrix[rows-1][c]);
        }
        return ans;
    }
};