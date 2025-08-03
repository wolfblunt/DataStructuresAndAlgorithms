// Zero Array Transformation I

// Using Sweep Line Technique

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        for(auto a: queries)
        {
            prefix[a[0]]++;
            prefix[a[1]+1]--;
        }

        for(int i=1;i<=n;i++)
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
};