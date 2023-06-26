// Tallest Billboard

class Solution {
public:
    const int offset = 5000;
    int helper(vector<int>& rods, int index, int diff, vector<vector<int>> &dp, int n)
    {
        if(index==n)
        {
            if(diff == 0)
            {
                return 0;
            }
            return -1e4;
        }

        int d = diff + offset;

        int &ans = dp[index][d];
        if(ans != -1)
        {
            return ans;
        }

        int option1 = helper(rods, index+1, diff, dp, n);  // not take option in any two sets
        int option2 = rods[index] + helper(rods, index+1, diff + rods[index], dp, n);  // take rod in set1 (or option1)
        int option3 = helper(rods, index+1, diff - rods[index], dp, n);  // take rod in set2 (or option2)

        return ans = max(option1, max(option2, option3));
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n+1, vector<int>(10001,-1));
        int ans = helper(rods, 0, 0, dp, n);
        if(ans<0)
            return 0;
        
        return ans;
    }
};