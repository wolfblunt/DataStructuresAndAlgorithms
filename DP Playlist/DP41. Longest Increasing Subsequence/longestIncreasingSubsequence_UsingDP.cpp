// Longest Increasing Subsequence - Using DP

class Solution {
public:
    int lis(vector<int>& nums, int index, int prevIndex, vector<vector<int>> dp)
    {
        if(index == nums.size())
        {
            return 0;
        }

        if(dp[index][prevIndex+1] != -1)
        {
            return dp[index][prevIndex+1];
        }

        int notTake = 0 + lis(nums, index+1, prevIndex, dp);
        int take = INT_MIN;
        if(prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + lis(nums, index+1, index, dp);
        }

        return dp[index][prevIndex + 1] = max(take, notTake);
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));  // {index, prevIndex}
        // prevIndex starts with -1 means nothing taken for index 0, but -1 array indexing starts at 0
        // so we need to do coordinate shift for prevIndex position

        return lis(nums, 0, -1, dp);
    }
};