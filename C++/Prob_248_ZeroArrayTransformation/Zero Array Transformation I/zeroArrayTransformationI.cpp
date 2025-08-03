// Zero Array Transformation I - O(Q+N)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixArr(n+1, 0);

        for(auto a: queries)
        {
            prefixArr[a[0]]++;
            prefixArr[a[1]+1]--;
        }

        for(int i=1;i<=n;i++)
        {
            prefixArr[i] += prefixArr[i-1];
        }

        for(int i=0;i<n;i++)
        {
            if(prefixArr[i] < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};