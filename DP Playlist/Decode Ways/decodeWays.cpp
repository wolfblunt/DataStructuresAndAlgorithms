// Decode Ways

class Solution {
public:
    int helper(string &s, int index, vector<int> &dp)
    {
        if(index == s.length())
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int res = 0;
        if(s[index] == '0')
        {
            return 0;
        }

        res += helper(s, index+1, dp); // one digit

        // two digit
        if(index+1 < s.length() && (s[index] == '1' || s[index] == '2' && s[index+1] < '7'))
        {
            res += helper(s, index+2, dp);
        }


        return dp[index] = res;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return helper(s,0,dp);
    }
};