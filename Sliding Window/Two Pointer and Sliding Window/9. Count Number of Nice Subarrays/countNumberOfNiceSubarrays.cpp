// Count Number of Nice Subarrays - O(n) + O(n) = O(n)

class Solution {
public:
    int noOfSubarrayEqualsK(vector<int>& nums, int k)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int odd = 0;
        int count = 0;
        for(int right=0;right<n;right++)
        {
            if(nums[right] % 2 == 1)
            {
                odd++;
            }
            while(left <= right && odd > k)
            {
                if(nums[left] % 2)
                {
                    odd--;
                }
                left++;
            }

            count += (right-left+1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return noOfSubarrayEqualsK(nums, k) - noOfSubarrayEqualsK(nums, k-1);
    }
};