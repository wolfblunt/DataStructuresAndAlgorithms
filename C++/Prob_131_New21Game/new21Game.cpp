// New 21 Game

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || k+maxPts <= n)
        {
            return (double)1.0;
        }
        
        vector<double> dp(n+1, 0.0);

        dp[0] = 1.0;
        double runningSum = dp[0];
        double result = 0.0;

        for(int i=1;i<n;i++)
        {
            // Calculating dp[i] assuming runningSum is already been correctly prepared
            dp[i] = runningSum/(double)maxPts;

            // handle the front end of running sum
            if(i < k)
            {
                runningSum += dp[i];
            }
            else
            {
                result += dp[i];
            }

            // handle the tail end of the running Sum
            if(i-maxPts >= 0)
            {
                runningSum -= dp[i-maxPts];
            }
        }

        return result;
    }
};