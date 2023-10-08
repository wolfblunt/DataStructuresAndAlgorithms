// Max Dot Product of Two Subsequences

class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1 == nums1.size() || index2 == nums2.size())
        {
            return 0;
        }
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        int option1 = nums1[index1] * nums2[index2] + helper(nums1, nums2, index1+1, index2+1, dp);
        int option2 = helper(nums1, nums2, index1+1, index2, dp);
        int option3 = helper(nums1, nums2, index1, index2+1, dp);

        return dp[index1][index2] = max({option1, option2, option3});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int firstMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMax = INT_MIN;
        int secondMin = INT_MAX;

        for(auto a: nums1)
        {
            firstMax = max(firstMax, a);
            firstMin = min(firstMin, a);
        }

        for(auto a: nums2)
        {
            secondMax = max(secondMax, a);
            secondMin = min(secondMin, a);
        }

        // if one of the array contains all negative values
        if((firstMax < 0 && secondMin > 0) || (secondMax < 0 && firstMin > 0))
        {
            return max(firstMax*secondMin, secondMax*firstMin);
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(nums1, nums2, 0, 0, dp);
    }
};