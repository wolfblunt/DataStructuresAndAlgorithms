// Total Decoding Messages - O(n)

class Solution {
  public:
    const int mod = 1e9+7;
  
    int helper(string &digits, int n, vector<int> &dp)
    {
        if(n==0 || n == 1)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int count = 0;
        
        if(digits[n-1] >= '1')
        {
            count = (count + helper(digits, n-1, dp) % mod) % mod;
        }
        if(digits[n-2] == '1' || digits[n-2] == '2' && digits[n-1] <= '6')
        {
            count = (count + helper(digits, n-2, dp) % mod) % mod;
        }
        
        return dp[n] = count%mod;
    }
  
    int countWays(string &digits) {
        int n = digits.size();
        if(digits[0] == '0')
        {
            return 0;
        }
        vector<int> dp(n+1, -1);
        
        return helper(digits, n, dp);
    }
};