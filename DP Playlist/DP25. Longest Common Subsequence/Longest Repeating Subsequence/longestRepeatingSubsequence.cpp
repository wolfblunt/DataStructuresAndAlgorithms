// Longest Repeating Subsequence - Memoization

class Solution {
	public:
	    int helper(string &str, int i, int j, vector<vector<int>> &dp)
	    {
	        if(i==0 || j==0)
	        {
	            return 0;
	        }
	        if(dp[i][j]!=-1)
	        {
	            return dp[i][j];
	        }
	        if(str[i-1] == str[j-1] && i!=j)
	        {
	            return dp[i][j] = 1 + helper(str, i-1, j-1, dp);
	        }
	        
	        return dp[i][j] = 0 + max(helper(str, i-1,j,dp), helper(str,i,j-1,dp));
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
		    return helper(str, n, n, dp);
		}

};