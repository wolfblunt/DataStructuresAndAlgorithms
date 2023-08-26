// Number of String breaker
// String Breaker - https://www.codingninjas.com/studio/problems/string-breaker_1094886

#include <bits/stdc++.h>
int dp[51];
int f(int L,int N,string &s,unordered_map<string,int> &hashmap)
{
    if(L == N || hashmap.find(s.substr(L,N-L)) != hashmap.end()) // if whole remaining word found in dict
    {
        return 0;
    }
    if(dp[L] != -1)
    {
        return dp[L];
    }
    string subString;
    int minBreaks = N << 1;
    for(int R=L;R<N;R++)
    {
        subString.push_back(s[R]);
        if(hashmap.find(subString) != hashmap.end())
        {
            int currBreaks = 1 + f(R+1,N,s,hashmap);
            minBreaks = min(minBreaks,currBreaks);
        }
    }
    return dp[L] = minBreaks;
}

int stringBreaker(string s, int n, vector<string> dictionary) 
{
    memset(dp,-1,sizeof dp);
    int N = s.size();
    unordered_map<string,int> hashmap;
    for(string &word : dictionary)
    {
        hashmap[word] = 1;
    }
    int minBreaks = f(0,N,s,hashmap);
    return (minBreaks > N ? -1 : minBreaks);

}
