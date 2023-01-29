// Unique Paths

class Solution {
public:
    int findUnique(int m, int n, vector<vector<int>>& dp)
    {
        if(n<0 || m<0)
        {
            return 0;
        }
        if(n==0 || m==0)
        {
            return 1;
        }
        if(dp[m][n] !=-1)
        {
            return dp[m][n];
        }
        return  dp[m][n] = findUnique(m-1,n,dp) + findUnique(m,n-1,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return findUnique(m-1,n-1,dp);
    }
};