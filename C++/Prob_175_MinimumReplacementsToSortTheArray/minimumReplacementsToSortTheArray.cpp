// Minimum Replacements to Sort the Array

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long n = nums.size();
        long long maxMinValue = nums[n-1];
        long long result = 0;
        for(long long i=n-2;i>=0;i--)
        {
            long long parts = ceil(nums[i]/(double)maxMinValue);
            result += (parts-1);
            maxMinValue = nums[i] / parts;
        }
        return result;
    }
};