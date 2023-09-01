//  Minimum Number of Taps to Open to Water a Garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        int i = 0;
        for(int r=0;r<=n;r++)
        {
            int start = max(0, i-ranges[r]);
            int end = min(n, i+ranges[r]);

            for(int j=start+1;j<end+1;j++)
            {
                dp[j] = min(dp[j], dp[start]+1);
            }
            i++;
        }

        if(dp[n] >= 1e9)
        {
            return -1;
        }

        return dp[n];
    }
};