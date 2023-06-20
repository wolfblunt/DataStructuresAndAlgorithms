// Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int low = 0;
        int high = nums.size() - 1;

        //first occurrence
        while(low<=high)
        {
            int mid = low + ((high - low) / 2);
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                if(mid == low || nums[mid] != nums[mid - 1])
                {
                    ans[0] = mid;
                    break;
                }
                else
                {
                    high = mid - 1;
                    ans[0] = mid-1;
                }
            }
        }

        low = 0;
        high = nums.size() - 1;
        //last occurrence
        while(low<=high)
        {
            int mid = low + ((high - low) / 2);
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                if(mid == high || nums[mid] != nums[mid + 1])
                {
                    ans[1] = mid;
                    break;
                }
                else
                {
                    low = mid + 1;
                    ans[1] = mid + 1;
                }
            }
        }

        return ans;
    }
};