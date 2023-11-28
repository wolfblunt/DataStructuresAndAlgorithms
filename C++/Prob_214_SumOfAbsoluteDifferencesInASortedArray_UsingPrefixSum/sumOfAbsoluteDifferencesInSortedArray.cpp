// Sum of Absolute Differences in a Sorted Array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int sum_diff = i*nums[i] - prefixSum[i] + (prefixSum[n] - prefixSum[i]) - (n-i)*nums[i];
            ans.push_back(sum_diff);
        }

        return ans;
    }
};