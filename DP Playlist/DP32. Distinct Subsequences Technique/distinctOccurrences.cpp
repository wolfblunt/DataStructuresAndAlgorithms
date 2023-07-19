// Distinct Occurrences - Memoization

class Solution {
public:
    int helper(string s, string t, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index2 == 0) // if length of t is exhausted then we get our match
        {
            return 1;
        }

        if(index1 == 0)  // if string s is exhausted and string t is not
        {
            return 0;
        }

        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        if(s[index1-1] == t[index2-1])
        {
            return dp[index1][index2] = helper(s,t,index1-1,index2-1,dp) + helper(s,t,index1-1,index2,dp);
            // when we consider the matched char + we skip the matched char and find for other char
        }
        return dp[index1][index2] = helper(s,t,index1-1,index2,dp);
        // when the char in s is not match with t, so we move to next character
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return helper(s,t,n,m,dp);
    }
};