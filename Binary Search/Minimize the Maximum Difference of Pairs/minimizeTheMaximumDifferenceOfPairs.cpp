// Minimize the Maximum Difference of Pairs

class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int p, int n)
    {
        int count = 0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1] - nums[i] <= mid)
            {
                count++;
                i++;
            }

            if(count>=p)
            {
                return true;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(nums,mid,p, n))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};