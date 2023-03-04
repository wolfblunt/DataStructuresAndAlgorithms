// Count Subarrays With Fixed Bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int minStart = -1;
        int maxStart = -1;
        int start = 0;
        int n = nums.size();
        bool maxFound = false;
        bool minFound = false;

        for(int i=0;i<n;i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                maxFound = false;
                minFound = false;
                start = i+1;
            }

            if(nums[i]==minK)
            {
                minStart = i;
                minFound = true;
            }

            if(nums[i]==maxK)
            {
                maxStart = i;
                maxFound = true;
            }

            if(minFound && maxFound)
            {
                result += (min(minStart, maxStart) - start) + 1;
            }
        }
        return result;
    }
};