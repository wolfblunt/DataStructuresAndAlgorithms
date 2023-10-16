// Painting the Walls

class Solution {
public:
    int helper(vector<int>& cost, vector<int>& time, int index, int remainRoom, vector<vector<int>> &dp)
    {
        if(remainRoom <= 0)
        {
            return 0;
        }
        if(index >= cost.size())
        {
            return 1e9;
        }
        if(dp[index][remainRoom] != -1)
        {
            return dp[index][remainRoom];
        }

        int notPick = 0 + helper(cost, time, index+1, remainRoom, dp);
        int pick = cost[index] + helper(cost, time, index+1, remainRoom - time[index] - 1, dp); // remainRoom - nonpaid Painter rooms equals total time taken by paid painter for that index room - 1(for paid painter)

        return dp[index][remainRoom] = min(pick, notPick);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));  // dp[roomIndex][remainingRooms]
        int remainRoom = n;
        return helper(cost, time, 0, remainRoom, dp);
    }
};