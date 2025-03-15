// House Robber IV - O(n^2)

class Solution {
public:
    int helper(vector<int>& nums, int index, int k, vector<vector<int>> &dp)
    {
        if(k==0)
        {
            return 0;
        }

        if(index < 0)
        {
            return INT_MAX;
        }

        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }

        int notTake = helper(nums, index-1, k, dp);
        int take = max(nums[index], helper(nums, index-2, k-1, dp));

        return dp[index][k] = min(take, notTake);
    }


    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return helper(nums, n-1, k, dp);
    }
};