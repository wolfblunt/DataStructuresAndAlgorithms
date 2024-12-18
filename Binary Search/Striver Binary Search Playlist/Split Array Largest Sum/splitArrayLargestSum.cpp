// Split Array Largest Sum

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int helper(vector<int>& nums, int mid)
    {
        int split = 1;
        int sum = 0;
        for(auto a: nums)
        {
            if(a+sum <= mid)
            {
                sum += a;
            }
            else
            {
                split++;
                sum = a;
            }
        }

        return split;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int split = helper(nums, mid);
            if(split > k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return low;
    }
};