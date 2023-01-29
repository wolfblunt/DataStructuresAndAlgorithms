#include<bits/stdc++.h>
class Solution {
public:
    int numTilings(int n)
    {
        vector<long long> dp(1001);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int mod = 1e9+7;
        for(int i=4;i<=n;i++)
        {
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i]%=mod;
        }
        return dp[n];
    }
};