// Longest Common Substring
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string str1, string str2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int answer = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    answer = max(answer, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return answer;
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
