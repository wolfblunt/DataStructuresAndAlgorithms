// Minimum steps to minimize n as per given condition

class Solution{

	public:
	int helper(int n, vector<int>& dp)
	{
	    if(n <= 1)
	    {
	        return 0;
	    }
	    if(dp[n] != -1)
	    {
	        return dp[n];
	    }
	    int step_two = INT_MAX;
	    int step_three = INT_MAX;
	    if(n%3 == 0)
	    {
	        step_three = 1 + helper(n/3, dp);
	    }
	    if(n%2 == 0)
	    {
	        step_two = 1 + helper(n/2, dp);
	    }
	    
	    int step_one = 1 + helper(n-1, dp);
	    
	    return dp[n] = min(step_one, min(step_two,step_three));
	}
	
	int minSteps(int N) 
	{ 
	    vector<int> dp(N+1, -1);
	    return helper(N, dp);
	} 
};