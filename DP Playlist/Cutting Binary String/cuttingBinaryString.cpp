// Cutting Binary String: O(n^2)

class Solution {
  public:
    int helper(string &s, int index, int n, unordered_map<int, int> &um, vector<int> &dp)
    {
        if(index == n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int minCuts = n+1;
        int num = 0;
        for(int j=index;j<n;j++)
        {
            num = num*2 + (s[j]-'0');
            if(s[index] == '1' && um.find(num) != um.end())
            {
                minCuts = min(minCuts, helper(s, j+1, n, um, dp)+1);
            }
        }
        
        return dp[index] = minCuts;
    }
  
    int cuts(string s) {
        int n = s.length();
        if(n==0 || s[0] == '0' || s[n-1] == '0')
        {
            return -1;
        }
        
        vector<int> dp(n, -1);
        unordered_map<int, int> um;
        for(int i=1;i<=1e9;i=i*5)
        {
            um[i] = 1;
        }
        
        int ans = helper(s, 0, n, um, dp);
        if(ans > n)
        {
            return -1;
        }
        return ans;
    }
};