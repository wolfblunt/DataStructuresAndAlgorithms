int fn(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }
    
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point = points[day][task] + fn(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return fn(n-1, 3, points, dp);
}