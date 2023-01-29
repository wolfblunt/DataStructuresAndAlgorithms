// Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int lcs(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(s1[index1] == s2[index2])
        {
            int match = 1 + lcs(s1,s2,index1-1,index2-1,dp);
            return dp[index1][index2] = match;
        }
        int notMatch = 0 + max(lcs(s1,s2,index1-1,index2,dp), lcs(s1,s2,index1,index2-1,dp));
        return dp[index1][index2] = notMatch;
    }
    
    int longestPalinSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s,s2,n-1,n-1,dp);
    }
};


int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
