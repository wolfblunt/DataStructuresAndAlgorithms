// Strange Printer

class Solution {
public:
    int helper(string s, int i, int j, vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int answer = 1 + helper(s, i+1, j, dp);
        char firstChar = s[i];
        for(int k=i+1;k<=j;k++)
        {
            if(firstChar == s[k])
            {
                int betteranswer = helper(s, i, k-1, dp) + helper(s, k+1, j, dp);
                answer = min(answer, betteranswer);
            }
        }
        return dp[i][j] = answer;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(s, 0, n-1, dp);
    }
};