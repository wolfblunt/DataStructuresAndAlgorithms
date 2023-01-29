#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;

long long int powerCalc(long long int x, long long int n)
{
    long long int answer = 0;
    while(n)
    {
        if(n%2)
        {
            answer = (answer * (x)%1000000007)%1000000007;
            n = n-1;
        }
        else{
            x = ((x)%1000000007 * (x)%1000000007) % 1000000007;
            n = n>>1;
        }
    }
    
    return answer;
}

long long int powerD(long long int t, vector<long long int> &dp)
{
    if(t<2 && t>=0)
    {
        return dp[t] = t+1;
    }
    if(dp[t-2]!=-1 && dp[t-1]!=-1)
    {
        dp[t] = powerCalc(dp[t-2], dp[t-1]);
    }
    else if(dp[t-2]!=-1 && dp[t-1]==-1)
    {
        dp[t-1] = powerD(t-1, dp);
        dp[t] = powerCalc(dp[t-2], dp[t-1]);
    }
    else{
        dp[t-2] = powerD(t-2,dp);
        dp[t-1] = powerD(t-1,dp);
        dp[t] = powerCalc(dp[t-2], dp[t-1]);
    }
    return d[t];
}

int main() {
    long long int t;
    cin>>t;
    vector<long long int> dp(t+1, -1);
    
    cout<<powerD(t, dp);
    return 0;
}