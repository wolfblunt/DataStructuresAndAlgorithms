// min Price

class Solution {
  public:
    long long helper(vector<int> &p, vector<int> &f, long long index, long long remaining, vector<vector<long long>> &dp)
    {
        if(remaining <= 0)
        {
            return 0;
        }
        
        if(index == 0)
        {
            return 1e13;
        }
        
        if(dp[index][remaining] != -1)
        {
            return dp[index][remaining];
        }
        
        dp[index][remaining] = min(helper(p,f,index-1,remaining-1-f[index-1],dp) + p[index-1], helper(p,f,index-1,remaining,dp));
        
        return dp[index][remaining];
    }
  
    long long minCost(int n, vector<int> &p, vector<int> &f) {
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1)); //dp[index][remaining]
        return helper(p, f, n, n, dp);
    }
};