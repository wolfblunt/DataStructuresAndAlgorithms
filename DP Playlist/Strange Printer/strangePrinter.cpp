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

        // in case, current character is not repeated in the rest of the string
        int answer = 1 + helper(s, i+1, j, dp);

        char firstChar = s[i];
        for(int k=i+1;k<=j;k++)
        {
            // if repeated then update the answer
            if(firstChar == s[k])
            {
                // splitting from i -> k - 1(remove the last character)
                // and from k + 1 -> j
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