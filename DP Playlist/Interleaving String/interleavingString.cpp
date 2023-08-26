// Interleaving String

class Solution {
public:
    bool helper(string &s1, string &s2, string &s3, int index1, int index2, vector<vector<int>> &dp, int k)
    {
        if(index1+index2 == k)
        {
            return 1;
        }
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        bool match = 0;
        if(index1 < s1.size() && s1[index1] == s3[index1 + index2])
        {
            match = (match | helper(s1,s2,s3,index1+1,index2,dp,k));
        }
        if(index2 < s2.size() && s2[index2] == s3[index1 + index2])
        {
            match = (match | helper(s1,s2,s3,index1,index2+1,dp,k));
        }

        return dp[index1][index2] = match;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();
        if(n+m!=k)
        {
            return false;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(s1,s2,s3,0,0,dp,k);
    }
};