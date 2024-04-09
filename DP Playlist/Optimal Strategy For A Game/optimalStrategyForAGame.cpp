// Optimal Strategy For A Game : O(n*n)

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long helper(int first, int last, int arr[], vector<vector<long long>> &dp)
    {
        if(first>last)
        {
            return 0;
        }
        if(dp[first][last]!=-1)
        {
            return dp[first][last];
        }
        
        long long choice1 = arr[first] + min(helper(first+2, last, arr, dp), helper(first+1, last-1, arr, dp));
        long long choice2 = arr[last] + min(helper(first, last-2, arr, dp), helper(first+1, last-1, arr, dp));
        
        return dp[first][last] = max(choice1, choice2);
    }
    
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return helper(0,n-1,arr,dp);
    }
};