// Find the Value of the Partition

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++)
        {
            ans = min(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};