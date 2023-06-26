// Longest Arithmetic Progression

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int ans = 2;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff = nums[j] - nums[i];
                if(dp[j].find(diff) == dp[j].end())
                {
                    dp[i][diff] = 2;
                }
                else
                {
                    dp[i][diff] = dp[j][diff] + 1;
                    ans = max(ans, dp[i][diff]);
                }
            }
        }

        return ans;
    }
};