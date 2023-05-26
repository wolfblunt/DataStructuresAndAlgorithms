// Stone Game II

class Solution {
public:
    int helper(vector<int>& piles, vector<vector<int>> &dp, vector<int> &suffixSum, int i, int M)
    {
        if(i==piles.size())
        {
            return 0;
        }

        if(i+2*M >= piles.size())
        {
            return suffixSum[i];
        }

        if(dp[i][M]!=-1)
        {
            return dp[i][M];
        }

        int result = 0;
        for(int x=1;x<=2*M;x++)
        {
            result = max(result, suffixSum[i]-helper(piles, dp, suffixSum, i+x, max(x,M)));
        }
        return dp[i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        if(piles.empty())
        {
            return 0;
        }
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));  // dp[i][m]
        vector<int> suffixSum(n);
        suffixSum[n-1] = piles[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffixSum[i] = piles[i] + suffixSum[i+1];
        }

        return helper(piles, dp, suffixSum, 0, 1);
    }
};