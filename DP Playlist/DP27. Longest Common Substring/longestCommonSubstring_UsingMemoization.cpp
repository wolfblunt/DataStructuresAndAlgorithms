// Longest Common Substring Using Memoization

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int ans = INT_MIN;
    int helper(string &S1, string &S2, int idx1, int idx2, vector<vector<int>> &dp, int n, int m)
    {
        if(idx1==n || idx2==m)
        {
            return 0;
        }
        if(dp[idx1][idx2]!=-1)
        {
            return dp[idx1][idx2];
        }
        
        if(S1[idx1] != S2[idx2])
        {
            return dp[idx1][idx2] = 0;
        }
        else
        {
            dp[idx1][idx2] = 1 + helper(S1, S2, idx1+1, idx2+1, dp, n, m); 
            // ans = max(ans, dp[idx1][idx2]);
            return dp[idx1][idx2];
        }
    }
    
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans, helper(S1, S2, i, j, dp, n, m));
            }
        }
        
        return ans;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}