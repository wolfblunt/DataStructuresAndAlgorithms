// Count number of hops

class Solution
{
    public:
    long long mod = 1000000007;
    int helper(int index, vector<long long> &dp)
    {
        if(index==1 || index==0)
        {
            return 1;
        }
        if(index==2)
        {
            return 2;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        return dp[index] = (helper(index-1, dp) % mod + helper(index-2, dp) % mod + helper(index-3, dp) % mod) % mod;
    }
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long> dp(n+1, -1);
        dp[0] = 1;
        return helper(n,dp);
    }
};