// Sum of all substrings of a number

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int mod = 1e9+7;
        long long n = s.length();
        vector<long long> dp(n, 0);
        dp[0] = s[0]-'0';
        long long res = dp[0]%mod;
        for(long long i=1;i<n;i++)
        {
            dp[i] = (((i+1)*(s[i]-'0')%mod)%mod + (dp[i-1]%mod*10)%mod)%mod;
            res = (res%mod + dp[i])%mod;
        }
        
        return res%mod;
    }
};