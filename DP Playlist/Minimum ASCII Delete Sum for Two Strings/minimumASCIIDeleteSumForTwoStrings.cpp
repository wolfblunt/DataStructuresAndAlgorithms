// Minimum ASCII Delete Sum for Two Strings

class Solution {
public:
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        {
            return 0;
        }

        if(i<0 && j>=0)
        {
            int sum = 0;
            for(int k=j;k>=0;k--)
            {
                sum+=s2[k];
            }
            return sum;
        }

        if(i>=0 && j<0)
        {
            int sum = 0;
            for(int k=i;k>=0;k--)
            {
                sum+=s1[k];
            }
            return sum;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s1[i] == s2[j])
        {
            return helper(s1,s2,i-1,j-1,dp);
        }
        
        return dp[i][j] = min(s1[i] + helper(s1,s2,i-1,j,dp), s2[j] + helper(s1,s2,i,j-1,dp));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(s1,s2,n-1,m-1,dp);
    }
};