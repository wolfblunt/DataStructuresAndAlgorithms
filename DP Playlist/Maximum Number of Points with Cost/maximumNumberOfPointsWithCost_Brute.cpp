// Maximum Number of Points with Cost - O(n*m*m) where n=rows, m=cols

class Solution {
public:
    long long helper(vector<vector<int>>& points, int i, int j, int n, int m, vector<vector<long long>>& dp)
    {
        if(i==0)
        {
            return points[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long maxPoint = 0;
        for(int k=0;k<m;k++)
        {
            maxPoint = max(maxPoint, helper(points, i-1, k, n, m, dp) - abs(j-k));
        }

        return dp[i][j] = maxPoint + points[i][j];
    }

    long long maxPoints(vector<vector<int>>& points) {
        long long n = points.size();
        long long m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m,-1));
        long long ans = 0;
        for(int j=0;j<m;j++)
        {
            ans = max(ans, helper(points, n-1, j, n, m , dp));
        }

        return ans;
    }
};