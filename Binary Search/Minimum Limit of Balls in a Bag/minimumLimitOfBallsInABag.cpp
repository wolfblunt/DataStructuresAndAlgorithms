// Minimum Limit of Balls in a Bag: O(Log(Max(Nums)))

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool helper(vector<int>& nums, int penalty, int maxOperations)
    {
        int totalOps = 0;
        for(auto a: nums)
        {
            totalOps += (a-1)/penalty;
        }

        return totalOps<=maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int minPenalty = high;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(helper(nums, mid, maxOperations))
            {
                minPenalty = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return minPenalty;
    }
};