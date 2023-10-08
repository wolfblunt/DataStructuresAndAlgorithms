// Apply Operations to Make Two Strings Equal

class Solution {
public:
    int helper(int left, int right, int x, vector<int> &v, vector<vector<int>> &dp)
    {
        if(left>=right)
        {
            return 0;
        }

        if(dp[left][right]!=-1)
        {
            return dp[left][right];
        }

        // 3 cases
        int case1 = min(x, v[left+1] - v[left]) + helper(left+2, right, x, v, dp);
        int case2 = min(x, v[right] - v[left]) + helper(left+1, right-1, x, v, dp);
        int case3 = min(x, v[right] - v[right-1]) + helper(left, right-2, x, v, dp);

        return dp[left][right] = min({case1, case2, case3});
    }

    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        int countBitsDiff = 0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                countBitsDiff++;
                v.push_back(i);
            }
        }

        if(countBitsDiff % 2)
        {
            return -1;
        }

        if(countBitsDiff == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(countBitsDiff+1, vector<int>(countBitsDiff+1, -1));
        return helper(0, countBitsDiff-1, x, v, dp);
    }
};