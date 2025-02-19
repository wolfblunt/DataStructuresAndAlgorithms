// Maximum Sum of 3 Non-Overlapping Subarrays - O(3*N)

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefixSum;
    int maxSumHelper(vector<int>& nums, int pos, int count, int& k)
    {
        if(count < 0 || count >= 3)
        {
            return 0;
        }
        if(pos > nums.size()-k)
        {
            return 0;
        }
        if(dp[pos][count]!=-1)
        {
            return dp[pos][count];
        }

        int notPick = maxSumHelper(nums, pos+1, count, k);
        int pick = maxSumHelper(nums, pos+k, count+1, k) + prefixSum[pos+k] - prefixSum[pos];

        return dp[pos][count] = max(pick, notPick);
    }

    void maxSumPathHelper(vector<int>& nums, int pos, int count, int& k, vector<int>& path)
    {
        if(count < 0 || count >= 3)
        {
            return;
        }
        if(pos > nums.size() - k)
        {
            return;
        }

        int pickIndexSum = maxSumHelper(nums, pos+k, count+1, k) + prefixSum[pos+k] - prefixSum[pos];
        int notPickIndexSum = maxSumHelper(nums, pos+1, count, k);

        if(pickIndexSum >= notPickIndexSum)
        {
            path.push_back(pos);
            maxSumPathHelper(nums, pos+k, count+1, k, path);
        }
        else
        {
            maxSumPathHelper(nums, pos+1, count, k, path);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        prefixSum = vector<int>(n+1, 0);
        dp = vector<vector<int>>(n+1, vector<int>(3, -1));

        for(int i=0;i<n;i++)
        {
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }

        int maxSum = maxSumHelper(nums, 0, 0, k);
        vector<int> path;
        maxSumPathHelper(nums, 0, 0, k, path);

        return path;
    }
};