// Minimum Insertion Steps to Make a String Palindrome

class Solution {
public:
    int helper(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1 < 0 || index2 < 0)
        {
            return 0;
        }

        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        if(s1[index1] == s2[index2])
        {
            return dp[index1][index2] = 1 + helper(s1,s2,index1-1,index2-1,dp);
        }

        return dp[index1][index2] = 0 + max(helper(s1,s2,index1-1,index2,dp), helper(s1,s2,index1,index2-1,dp));
    }


    int maximumPalindromicSubsequence(string s, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return helper(s,s2,n-1,n-1,dp);
    }

    int minInsertions(string s) {
        int n = s.length();
        return n - maximumPalindromicSubsequence(s, n);
    }
};