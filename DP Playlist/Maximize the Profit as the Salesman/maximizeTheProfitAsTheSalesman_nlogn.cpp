// Maximize the Profit as the Salesman - O(nlog(n))

class Solution {
public:
    int helper(vector<vector<int>>& offers, int index, vector<int>& dp)
    {
        if(index == offers.size())
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int notTake = helper(offers, index+1, dp);
        int low = index+1;
        int high = offers.size()-1;
        int newIndex = offers.size();
        while(low<=high)
        {
            int mid = low + (high-low) / 2;
            if(offers[mid][0] > offers[index][1])
            {
                high = mid-1;
                newIndex = mid;
            }
            else
            {
                low = mid+1;
            }
        }

        int take = offers[index][2] + helper(offers, newIndex, dp);

        return dp[index] = max(take, notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        int m = offers.size();
        vector<int> dp(m,-1);
        return helper(offers, 0, dp);
    }
};