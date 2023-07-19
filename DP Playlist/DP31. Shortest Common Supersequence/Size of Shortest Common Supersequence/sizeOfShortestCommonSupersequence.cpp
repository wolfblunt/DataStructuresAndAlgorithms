// Size of Shortest Common Supersequence - Memoization

class Solution
{
    public:
    int longestSubstring(string& text1, string& text2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1==0 || index2==0)
        {
            return 0;
        }
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        
        if(text1[index1-1]==text2[index2-1])
        {
            return dp[index1][index2] = 1+longestSubstring(text1, text2, index1-1, index2-1, dp);
            
        }
        int c1 = longestSubstring(text1, text2, index1-1, index2, dp);
        int c2 = longestSubstring(text1, text2, index1, index2-1, dp);
        return dp[index1][index2] = 0+max(c1,c2);
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string text1, string text2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        int lcs =  longestSubstring(text1, text2, n, m, dp);
        return n+m-lcs;
    }
};