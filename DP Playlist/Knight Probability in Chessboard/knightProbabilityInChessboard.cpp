// Knight Probability in Chessboard

class Solution {
public:
    double dp[26][26][102];
    int dirs[8][8] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

    double helper(int row,int col,int n,int k)
    {
        if(row < 0 || col < 0 || row >= n || col >= n) 
        {
            return 0;
        }
        if(k == 0)
        {
            return 1;
        }
        if(dp[row][col][k] != -1.0) 
        {
            return dp[row][col][k];
        }
        
       double ans = 0;
        
        for(auto a: dirs)
        {
            ans += helper(row+a[0], col+a[1], n, k-1)/8.0;
        }
        
        return dp[row][col][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<102;k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        return helper(row,column,n,k);
    }
};