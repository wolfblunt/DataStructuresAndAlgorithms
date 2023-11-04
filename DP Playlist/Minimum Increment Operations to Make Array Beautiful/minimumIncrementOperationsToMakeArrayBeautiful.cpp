// Minimum Increment Operations to Make Array Beautiful

class Solution {
public:
    long long helper(vector<int>& nums, int k, int index, vector<long long>& dp, int &n)
    {
        if(index > n-3)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }

        long long index1 = max(0, k-nums[index]) + helper(nums,k, index+1, dp, n);
        long long index2 = max(0, k-nums[index+1]) + helper(nums,k, index+2, dp, n);
        long long index3 = max(0, k-nums[index+2]) + helper(nums,k, index+3, dp, n);

        return dp[index] = min({index1, index2, index3});
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        return helper(nums, k, 0, dp, n);
    }
};