// Out of Boundary Paths - O(r*c*move)

class Solution {
public:
    const int mod = 1e9+7;
    int helper(int r, int c, int move, vector<vector<vector<int>>> &dp, int m, int n)
    {
        if(r<0 || r == m || c<0 || c==n)
        {
            return 1;
        }

        if(move == 0)
        {
            return 0;
        }

        if(dp[r][c][move]!=-1)
        {
            return dp[r][c][move];
        }

        int ans = 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto a: dirs)
        {
            ans = (ans + helper(r+a[0],c+a[1],move-1,dp,m,n)) % mod;
        }
        return dp[r][c][move] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(maxMove+1, -1))); // dp[r][c][move]
        return helper(startRow, startColumn, maxMove, dp, m, n);
    }
};


// Brute Force - (4^(r*c*move))

// class Solution {
// public:
//     const int mod = 1e9 + 7;

//     bool checkoutOfBounds(int m, int n, int r, int c) 
//     {
// 	    return r < 0 || r >= m || c < 0 || c >= n;
//     }
//     int findPaths(int m, int n, int maxMove, int r, int c) 
//     {
//         bool isOut = checkoutOfBounds(m,n,r,c);
//         if(isOut || !maxMove)
//         {
//             return isOut;
//         }
        
//         return (findPaths(m, n, maxMove-1, r + 1, c)  + 
// 			findPaths(m, n, maxMove-1, r - 1, c)  +    
// 			findPaths(m, n, maxMove-1, r, c + 1)  +    
// 			findPaths(m, n, maxMove-1, r, c - 1)) % mod;
//     }
// };