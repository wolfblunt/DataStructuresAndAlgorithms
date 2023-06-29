// Palindromic Partitioning

#include <bits/stdc++.h> 
bool isPalindrome(string s, int start, int end)
{
    while(start<=end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int helper(string &str, int start, vector<int>& dp)
{
    if(start == str.size())
    {
        return 0;
    }
    
    if(dp[start]!=-1)
    {
        return dp[start];
    }
    
    int minCost = INT_MAX;
    for(int i=start; i<str.size();i++)
    {
        if(isPalindrome(str, start, i))
        {
            int cost = 1+ helper(str, i+1, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[start] = minCost;
}
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return helper(str, 0, dp) - 1;  // doing -1 because it will insert partition at the end of the string also..  for Ex - a|b|c| but correct answer is a|b|c
}
