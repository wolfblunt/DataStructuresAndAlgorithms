// Find K-th Smallest Pair Distance
// O(n log n + n log W) | Binary Search + Sliding Window

class Solution {
public:
    bool isMidDiffGreaterThanK(vector<int>& nums, int mid, int k)
    {
        int left = 0;
        int count = 0;
        for(int right=1;right<nums.size();right++)
        {
            while(nums[right] - nums[left] > mid)
            {
                left++;
            }
            count += right-left;
        }

        return (count >= k);
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0; // smallest difference
        int right = nums[n-1]-nums[0];

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(isMidDiffGreaterThanK(nums, mid, k))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }

        return left;
    }
};