// Count digit groupings of a number

class Solution{
	public:
	int helper(int index, int prev, string& str, vector<vector<int>> &dp)
	{
	    if(index == str.length())
	    {
	        return 1;
	    }
	    if(dp[index][prev] != -1)
	    {
	        return dp[index][prev];
	    }
	    
	    int nextSum = 0;
	    int count = 0;
	    for(int j=index;j<str.length();j++)
	    {
	        nextSum += stoi(str.substr(j,1));
	        if(nextSum >= prev)
	        {
	            count += helper(j+1, nextSum, str, dp); 
	        }
	    }
	    
	    return dp[index][prev] = count;
	}
	
	int TotalCount(string str){
	    int n = str.length();
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += stoi(str.substr(i,1));
	    }
	    
	    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	    // dp[n][totalSum]
	    
	    sum = 0;
	    int totalCount = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += stoi(str.substr(i,1));
	        totalCount += helper(i+1,sum,str,dp);
	    }
	    return totalCount;
	}

};