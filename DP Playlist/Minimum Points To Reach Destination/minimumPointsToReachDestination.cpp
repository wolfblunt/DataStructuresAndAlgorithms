// Minimum Points To Reach Destination

class Solution{

	public:
	int helper(int i, int j, int m, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
	{
	    if(i==m-1 && j==n-1)
	    {
	        return 1-points[i][j];
	    }
	    if(i>=m || j>=n)
	    {
	        return INT_MAX;
	    }
	    if(dp[i][j]!=-1)
	    {
	        return dp[i][j];
	    }
	    
	    int op1 = helper(i+1,j,m,n,points,dp);
	    int op2 = helper(i,j+1,m,n,points,dp);
	    
	    return dp[i][j] = max(1, min(op1,op2)-points[i][j]);
	}
	
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,points,dp);
	} 
};