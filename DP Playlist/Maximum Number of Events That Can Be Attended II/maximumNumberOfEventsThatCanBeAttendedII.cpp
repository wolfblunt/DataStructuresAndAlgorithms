// Maximum Number of Events That Can Be Attended II

class Solution {
public:
    int helper(vector<vector<int>>& events, vector<vector<int>>& dp, int index, int k, int end)
    {
        if(index == events.size())
        {
            return 0;
        }

        if(k==0)
        {
            return 0;
        }

        if(events[index][0] <= end)
        {
            return helper(events, dp, index+1, k, end);
        }

        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }

        int pick = events[index][2] + helper(events, dp, index+1, k-1, events[index][1]);
        int notPick = 0 + helper(events, dp, index+1, k, end);
        return dp[index][k] = max(pick, notPick);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k+1,-1));
        return helper(events, dp, 0, k, 0);
    }
};