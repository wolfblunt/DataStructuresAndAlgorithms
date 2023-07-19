// Number of Longest Increasing Subsequence : O(n^2) + O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), cut(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1)
                {
                    dp[i] = dp[prev] + 1;
                    cut[i] = cut[prev];  // inherit
                }
                else if(nums[i] > nums[prev] && dp[i] == dp[prev] + 1)
                {
                    cut[i] += cut[prev];  // increase the count
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int msc = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] == maxi)
            {
                msc += cut[i];
            }
        }
        return msc;
    }
};