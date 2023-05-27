// Stone Game III

class Solution {
public:
    int helper(vector<int>& stoneValue, vector<int>& dp, int i)
    {
        int n = stoneValue.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=INT_MAX)
        {
            return dp[i];
        }

        int pickOne = stoneValue[i] - helper(stoneValue, dp, i+1);
        int pickTwo = INT_MIN;
        if(i+1<n)
        {
            pickTwo = stoneValue[i] + stoneValue[i+1] - helper(stoneValue, dp, i+2);
        }

        int pickThree = INT_MIN;
        if(i+2<n)
        {
            pickThree = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - helper(stoneValue, dp, i+3);
        } 

        return dp[i] = max(pickOne, max(pickTwo, pickThree));
    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MAX);  // stores difference

        int value = helper(stoneValue, dp, 0);

        if(value>0)
        {
            return "Alice";
        }
        else if(value<0)
        {
            return "Bob";
        }

        return "Tie";
    }
};