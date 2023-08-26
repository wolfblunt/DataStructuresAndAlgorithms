// Soup Servings

class Solution {
public:
    double helper(int a, int b, vector<vector<double>> &dp)
    {
        if(a<=0 && b>0)
        {
            return 1;
        }

        if(a<=0 && b<=0)
        {
            return 0.5;
        }

        if(a>0 && b<=0)
        {
            return 0;
        }

        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }

        double first = helper(a-100, b, dp);
        double second = helper(a-75, b-25, dp);
        double third = helper(a-50, b-50, dp);
        double fourth = helper(a-25, b-75, dp);

        return dp[a][b] = 0.25*(first + second + third + fourth);
    }

    double soupServings(int n) {
        if(n>=5000)
        {
            return 1.0;  // after n>=5000 the probability is almost equal to 1.
        }
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return helper(n, n, dp);
    }
};