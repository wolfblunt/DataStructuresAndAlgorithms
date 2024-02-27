// Perfect Squares

class Solution {
public:
    int helper(int n, vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }

        int minValue = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int t = i*i;
            minValue = min(minValue, 1+helper(n-t,dp));
        }

        return dp[n] = minValue;
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};