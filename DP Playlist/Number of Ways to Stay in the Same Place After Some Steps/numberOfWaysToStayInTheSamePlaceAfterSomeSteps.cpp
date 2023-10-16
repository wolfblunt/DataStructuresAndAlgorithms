// Number of Ways to Stay in the Same Place After Some Steps

class Solution {
public:
    int mod = 1e9+7;

    int helper(int steps, int arrLen, int position, vector<vector<int>> &dp)
    {
        if(position < 0 || position >= arrLen)
        {
            return 0;
        }
        if(steps == 0)
        {
            return position == 0 ? 1: 0;
        }

        if(dp[position][steps] != -1)
        {
            return dp[position][steps];
        }

        int ways = helper(steps-1, arrLen, position, dp) % mod; //stay
        ways = (ways + helper(steps-1, arrLen, position-1, dp) % mod) % mod; // left
        ways = (ways + helper(steps-1, arrLen, position+1, dp) % mod) % mod; // right

        return dp[position][steps] = ways;
    }

    int numWays(int steps, int arrLen) {
        // arrLen - 10^6 but maxSteps is 500, so we can go more than 250 steps in any one direction then we will not be able to come back to index 0.
        // So we can reduce arrLen to max 250. - optimization
        arrLen = min(steps/2+1, arrLen); 
        vector<vector<int>> dp(arrLen, vector<int>(steps+1, -1));
        return helper(steps, arrLen, 0, dp);
    }
};