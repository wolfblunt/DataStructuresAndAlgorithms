// Wildcard Matching - Memoization

class Solution {
public:
    int helper(string &str, string &pattern, int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
        {
            return true;
        }

        if(i>0 && j==0)
        {
            return false; // if pattern gets exhausted but the string is remaining. So we return false because they are not same.
        }

        if(i==0 && j>0)
        {
        	// case when string gets exhausted but the pattern is still remaining
            for(int k=1;k<=j;k++)
            {
            	// if all the pattern chars are '*' then we will treat is a null or 0 character
            	// hence match the string but if anyone is not '*' then we will retur false
                if(pattern[k-1] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
        {
            return dp[i][j] = helper(str, pattern, i-1, j-1, dp); // match the '?' with the string str char and move to next character.
        }

        if(pattern[j-1] == '*')
        {
        	// skip the '*' char character from string pattern || match the current char of string with '*' of pattern and move to next char in str
            return dp[i][j] = (helper(str, pattern, i, j-1, dp) || helper(str, pattern, i-1, j, dp));
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  // doing one base indexing so that index will not go -ve
        return helper(s,p,n,m,dp);
    }
};