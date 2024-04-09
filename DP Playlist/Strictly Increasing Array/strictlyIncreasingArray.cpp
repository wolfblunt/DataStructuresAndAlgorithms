// Strictly Increasing Array

class Solution {
  public:
    int helper(vector<int>& nums, int index, int prev, vector<vector<int>> &dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        if(dp[index][prev+1] != -1)
        {
            return dp[index][prev+1];
        }
        
        int notTake = 0 + helper(nums, index+1, prev, dp);
        int take = 0;
        if(prev==-1 || (nums[index] > nums[prev] && nums[index]-nums[prev] >= index-prev))
        {
            take = 1 + helper(nums, index+1, index, dp);
        }
        
        return dp[index][prev+1] = max(take, notTake);
    }
    
    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int lis = helper(nums, 0, -1, dp);
        return n-lis;
    }
};