// Minimum Cost to Make Array Equal  -- trinary search

class Solution {
public:
    long long helper(vector<int>& nums, vector<int>& cost, int middle)
    {
        long long totalCost = 0L;
        for(int i=0;i<nums.size();i++)
        {
            totalCost += 1LL * abs(nums[i] - middle) * cost[i];
        }
        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        long long ans = 0;

        while(low < high)
        {
            int mid = low + (high - low) / 2;
            long long cost1 = helper(nums, cost, mid);
            long long cost2 = helper(nums, cost, mid+1);

            if(cost1 > cost2)
            {
                low = mid + 1;
                ans = cost2;
            }
            else
            {
                high = mid;
                ans = cost1;
            }
        }

        return ans;
    }
};