// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int maxRecursive(int index, vector<int> &v, int k, vector<int> &dp)
{
    if(index==0)
    {
        return v[index];
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int maxSteps = INT_MIN;
    for(int i=1;i<=k;i++)
    {
        if(index-i>0)
        {
            int jump = maxRecursive(index-i, v, k, dp) + v[index];
            maxSteps = max(maxSteps, jump);
        }
    }
    
    return dp[index]=maxSteps;
    
}

int maxFinalScore(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> dp(n+1, -1);
    int result = maxRecursive(n-1, v, k, dp);
    return result;
}

int main() {
    int t;
    cin>>t;
    vector<int> v;
    int i;
    cin>>i;
    for(int i=0;i<t;i++)
    {
        v.push_back(i);
    }
    int k;
    cin>>k;
    cout<<maxFinalScore(v, k);
    return 0;
}
