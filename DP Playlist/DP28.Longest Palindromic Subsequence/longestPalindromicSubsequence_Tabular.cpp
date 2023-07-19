// Longest Palindromic Subsequence - Tabular

class Solution{
  public:
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(), B.end());
        int n = A.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=n;index2++)
            {
                if(A[index1-1] == B[index2-1])
                {
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];
                }
                else
                {   
                    dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
                }

            }
        }
        return dp[n][n];
    }
};