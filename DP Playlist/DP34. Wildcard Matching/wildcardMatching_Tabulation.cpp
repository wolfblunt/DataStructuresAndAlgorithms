// Wildcard Matching - Tabulation

class Solution {
public:
    bool isMatch(string str, string pattern) {
        int n = str.length();
        int m = pattern.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));  // doing one base indexing so that index will not go -ve
        
        dp[0][0] = true;

        for(int i=1;i<=n;i++)
        {
            dp[i][0] = false;
        }

        for(int j=1;j<=m;j++)
        {
            bool flag = true;
            for(int k=1;k<=j;k++)
            {
                if(pattern[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(pattern[j-1] == '*')
                {
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                }
            }
        }

        return dp[n][m];
    }
};