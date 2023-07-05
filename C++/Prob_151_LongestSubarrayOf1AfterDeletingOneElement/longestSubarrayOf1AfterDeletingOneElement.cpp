// Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        int n = nums.size();
        int zeros = 0;
        int maxx = 0;

        while(end<n)
        {
            if(nums[end] == 0)
            {
                zeros++;
            }

            while(start < n && zeros == 2)
            {
                if(nums[start] == 0)
                {
                    zeros--;
                }
                start++;
            }

            maxx = max(maxx, end-start);
            end++;
        }
        return maxx;
    }
};