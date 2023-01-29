//Special Keyboard

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        if(n<6)
        {
            return n;
        }
        vector<int> dp(n+1,0);
        for(int i=0;i<7;i++)
        {
            dp[i]=i;
        }
        for(int i=7;i<=n;i++)
        {
            for(int j=i-3;j>=1;j--)
            {
                int temp = dp[j]*(i-j-1);
                if(temp>dp[i])
                {
                    dp[i]=temp;
                }
            }
        }
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends