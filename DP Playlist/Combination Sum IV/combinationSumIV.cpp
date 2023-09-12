// Combination Sum IV

class Solution {
public:
    int helper(vector<int>& nums, int n, int target, vector<int> &dp)
    {
        if(target == 0)
        {
            return 1;
        }
        if(target < 0)
        {
            return 0;
        }
        if(dp[target] != -1)
        {
            return dp[target];
        }

        int take = 0;

        for(int i=0;i<n;i++)
        {
            take += helper(nums, n, target-nums[i], dp);
        }

        return dp[target] = take;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, nums.size(), target, dp);
    }
};