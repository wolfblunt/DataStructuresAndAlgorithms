// Zero Array Transformation II

// Using Binary Search And Sweep Line Technique

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool helper(vector<int>& nums, int index, vector<vector<int>>& queries)
    {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=0;i<=index;i++)
        {
            prefix[queries[i][0]] += queries[i][2];
            prefix[queries[i][1]+1] -= queries[i][2];
        }

        for(int i=1;i<n;i++)
        {
            prefix[i] += prefix[i-1];
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i] > prefix[i])
            {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool isAllZero = true;
        for(auto a: nums)
        {
            if(a!=0)
            {
                isAllZero = false;
            }
        }

        if(isAllZero)
        {
            return 0;
        }

        int n = queries.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(helper(nums, mid, queries))
            {
                ans = mid+1;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }

        return ans;
    }
};