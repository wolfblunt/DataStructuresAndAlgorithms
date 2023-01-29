#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int helper(int W, int wt[], int val[], int index, vector<vector<int>>& dp)
    {
        if(index==0)
            if(wt[index]<=W)
                return val[index];
            else
                return 0;
        if(dp[index][W]!=-1)
        {
            return dp[index][W];
        }
        int notPick = 0 + helper(W, wt, val, index-1, dp);
        int pick = INT_MIN;
        if(wt[index]<=W)
            pick = val[index] + helper(W-wt[index], wt, val, index-1, dp);
        
        return dp[index][W] = max(pick, notPick);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1,-1));
       return helper(W, wt, val, n-1, dp);
       
    }
};


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}