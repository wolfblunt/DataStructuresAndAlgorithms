// Egg Dropping Puzzle

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int helper(int n, int k, vector<vector<int>> &dp)
    {
        if(n==1)
        {
            return k; // if egg = 1 then hame 1st floor se start karna padega to find threshold floor. So in worst cast (last floor) k floors check karni pad sakti hai
        }
        if(k==0 || k==1)
        {
            return k; // agar no. of floor 1 or 0 hui toh same answer rahega
        }
        
        if(dp[n][k] != -1)
        {
            return dp[n][k];
        }
        
        int ans =INT_MAX;
        
        for(int i=1;i<=k;i++)
        {
            // helper(n-1, i-1, dp) - ith floor ke neeche check karne ke liye -- we will go downwards if egg will be broken
            // helper(n, k-i, dp) - ith floor ke upar check karne ke liye -- if egg will not break then we will go upwards to find threshold floor 
            int temp = 1 + max(helper(n-1, i-1, dp) , helper(n, k-i, dp));  // worst case mai noOfAttempts find karne ke liye max lagaya hai
            ans = min(ans, temp);  // minimum of worstCase find karne ke liye min lagaya hai
        }
        
        return dp[n][k] = ans;
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(201, vector<int>(201, -1)); // {n,k} -> {noOfEggs, moOfFloor}
        return helper(n, k, dp);
    }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}