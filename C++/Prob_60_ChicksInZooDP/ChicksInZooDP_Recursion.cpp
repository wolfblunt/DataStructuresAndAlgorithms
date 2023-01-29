#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int findChicks(int n, vector<long long int>& dp)
    {
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n<=6)
        {
            return dp[n] = 3*findChicks(n-1, dp);
        }
        if(n==7)
        {
            return dp[n] = 3*findChicks(n-1, dp) - 3*findChicks(n-6,dp); // no parent
        }
        
        if(n>7)
        {
            return dp[n] = 3*findChicks(n-1, dp) - 2*findChicks(n-6,dp);
        }
    }
    
    long long int NoOfChicks(int n){
        vector<long long int> dp(n+1, -1);
        return findChicks(n, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        Solution obj;
        long long int ans = obj.NoOfChicks(N);
        cout << ans <<"\n";
    }
    return 0;
}