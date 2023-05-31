// Minimum Cost to Cut a Stick

class Solution {
public:
    // int dp[101][101];
    int helper(vector<int>& cuts, int i, int j, vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int mini = 1e9;
        for(int index = i; index<=j; index++)
        {
            int cost = cuts[j+1] - cuts[i-1] + helper(cuts, i, index-1, dp) + helper(cuts, index+1, j, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return helper(cuts, 1, c, dp);
    }
};