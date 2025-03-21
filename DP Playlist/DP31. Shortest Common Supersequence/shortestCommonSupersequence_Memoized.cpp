// Shortest Common Supersequence - O(N∗M)

class Solution {
public:
    int helper(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(str1[i-1] == str2[j-1])
        {
            return dp[i][j] = 1 + helper(str1, str2, i-1, j-1, dp);
        }

        int c1 = helper(str1, str2, i-1, j, dp);
        int c2 = helper(str1, str2, i, j-1, dp);

        return dp[i][j] = max(c1, c2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        helper(str1, str2, n, m, dp);

        int len = dp[n][m];
        int i = n;
        int j = m;
        string ans;
        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
            }
            else
            {
                ans.push_back(str2[j-1]);
                j--;
            }
        }

        while(i>0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }

        while(j>0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};