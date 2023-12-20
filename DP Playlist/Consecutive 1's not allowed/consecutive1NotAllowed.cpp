// Consecutive 1's not allowed

class Solution{
public:
    int mod = 1e9+7;
    long long helper(int index, int& n, int prev, vector<vector<ll>>& dp)
    {
        if(index==n)
        {
            return 1;
        }
        if(index>n)
        {
            return 0;
        }
        if(dp[index][prev] != -1)
        {
            return dp[index][prev];
        }
        
        ll ans = 0;
        if(prev != 1)
        {
            ans = (ans + helper(index+1, n, 1, dp)%mod + helper(index+1, n, 0, dp)%mod) % mod;
        }
        else
        {
            ans = (ans + helper(index+1, n, 0, dp)%mod) % mod;
        }
        
        return dp[index][prev] = ans%mod;
    }
    
	// #define ll long long
	ll countStrings(int n) {
	    vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
	    
	    int previous = 0;
	    int index = 0;
	    return helper(index, n, previous, dp);
	}
};