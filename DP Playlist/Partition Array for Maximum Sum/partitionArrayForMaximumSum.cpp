// Partition Array for Maximum Sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i=0;i<n;i++)
        {
            int currMax = 0;
            int currSum = 0;
            for(int j=i;j>=max(0,i-k+1);j--)
            {
                currMax = max(currMax, arr[j]);
                int sum = currMax*(i-j+1) + dp[j];
                currSum = max(currSum, sum);
            }

            dp[i+1] = currSum;
        }

        return dp[n];
    }
};