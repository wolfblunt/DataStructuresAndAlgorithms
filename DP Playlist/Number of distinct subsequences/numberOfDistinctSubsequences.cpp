// Number of distinct subsequences

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.length();
	    int mod = 1e9 + 7;
	    vector<int> dp(n+1,0);
	    unordered_map<char, int> um;
	    dp[0] = 1; // for empty character
	    for(int i=1;i<=n;i++)
	    {
	        dp[i] = (2*dp[i-1]) % mod;
	        char c = s[i-1];
	        if(um.find(c) != um.end())
	        {
	            
	            dp[i] = (dp[i] - dp[um[c] - 1] + mod) % mod;
	        }
	        um[c] = i;
	    }
	    return dp[n] % mod;
	}
};