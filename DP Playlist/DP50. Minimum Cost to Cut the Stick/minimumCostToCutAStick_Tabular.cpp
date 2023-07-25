// Minimum Cost to Cut a Stick - Tabular


int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    for(int i=c;i>=1;i--)
    {
        for(int j=1;j<=c;j++)
        {
            if(i>j)
            {
                continue;
            }
            int mini = 1e9;
            for(int index = i; index<=j; index++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}