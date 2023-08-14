// Check if There is a Valid Partition For The Array

class Solution {
public:
    bool helper(int index, vector<int>& nums, vector<int>& dp)
    {
        if(index < 0)
        {
            return true;
        }

        if(dp[index]!=-1)
        {
            return dp[index];
        }

        bool twoIdentical = false;
        bool threeIdentical = false;
        bool increaseSeq = false;

        if(index > 0 && nums[index] == nums[index-1])
        {
            twoIdentical = helper(index-2, nums, dp);
        }

        if(index > 1 && nums[index] == nums[index-1] && nums[index] == nums[index-2])
        {
            threeIdentical = helper(index-3, nums, dp);
        }

        if(index > 1 && nums[index] == nums[index-1]+1 && nums[index] == nums[index-2]+2)
        {
            increaseSeq = helper(index-3, nums, dp);
        }

        return dp[index] = twoIdentical || threeIdentical || increaseSeq;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return helper(n-1, nums, dp);
    }
};