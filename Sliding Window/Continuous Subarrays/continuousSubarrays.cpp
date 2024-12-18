// Continuous Subarrays - O(N)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int maxx = INT_MIN;
        int minn = INT_MAX;
        long long count = 0;
        long long windowSize;
        int left = 0;
        int right;
        int n = nums.size();
        for(right=0;right<n;right++)
        {
            maxx = max(maxx, nums[right]);
            minn = min(minn, nums[right]);

            if(maxx - minn > 2)
            {
                windowSize = right-left;
                count += (windowSize * (windowSize+1))/2;

                left = right;
                maxx = nums[right];
                minn = nums[right];

                while(left > 0 && abs(nums[right] - nums[left-1]) <= 2)
                {
                    left--;
                    maxx = max(maxx, nums[left]);
                    minn = min(minn, nums[left]);
                }

                if(left < right)
                {
                    windowSize = right-left;
                    count -= (windowSize * (windowSize+1))/2;
                }
            }
        }

        windowSize = right-left;
        count += (windowSize * (windowSize+1))/2;

        return count;
    }
};