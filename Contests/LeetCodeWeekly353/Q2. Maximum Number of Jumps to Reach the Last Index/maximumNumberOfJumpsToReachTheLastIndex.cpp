// Maximum Number of Jumps to Reach the Last Index

class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int> &dp, int index)
    {
        if(index==nums.size()-1)
        {
            return 0;
        }
        
        if(dp[index]!=INT_MIN)
        {
            return dp[index];
        }
        int v = nums[index];
        int maxJump = -1;
        for(int i=index+1;i<nums.size();i++)
        {
            if(i < nums.size() && abs(nums[index] - nums[i]) <= target)
            {
                int jump = helper(nums, target, dp, i);
                if(jump!=-1)
                    maxJump = max(maxJump, 1+jump);
            }
        }
        return dp[index] = maxJump;
        
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        return helper(nums, target, dp, 0);
    }
};