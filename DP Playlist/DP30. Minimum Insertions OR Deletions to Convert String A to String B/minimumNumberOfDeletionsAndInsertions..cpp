// Minimum number of deletions and insertions.

#include <bits/stdc++.h> 

int helper(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
{
    if(index1 < 0 || index2 < 0)
    {
        return 0;
    }

    if(dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if(s1[index1] == s2[index2])
    {
        return dp[index1][index2] = 1 + helper(s1,s2,index1-1,index2-1,dp);
    }

    return dp[index1][index2] = 0 + max(helper(s1,s2,index1-1,index2,dp), helper(s1,s2,index1,index2-1,dp));
}


int maximumPalindromicSubsequence(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return helper(s1,s2,n-1,m-1,dp);
}

int canYouMake(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();
    int lcs = maximumPalindromicSubsequence(str1, str2, n, m);
    int deletions = n - lcs;
    int insertions = m - lcs;
    return (insertions + deletions);
}