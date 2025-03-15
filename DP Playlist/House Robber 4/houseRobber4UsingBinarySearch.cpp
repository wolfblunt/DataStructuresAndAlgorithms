// House Robber IV - O(n*log(n))

class Solution {
public:
    int canRobMoreThanK(vector<int>& nums, int mid)
    {
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= mid)
            {
                count++;
                i++;
            }
        }

        return count;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(canRobMoreThanK(nums, mid) >= k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};