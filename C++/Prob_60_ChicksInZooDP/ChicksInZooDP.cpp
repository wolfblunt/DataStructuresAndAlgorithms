//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long int> dp(n+1,-1);
	    dp[1] = 1;
	    dp[0] = 0;
	    long long int noOfchick = 1;
	    for(int i=2;i<=n;i++)
	    {
	        if(i>6)
	        {
	            noOfchick -= dp[i-6];
	        }
	        dp[i] = noOfchick*2;
	        noOfchick += dp[i];
	    }
	    return noOfchick;
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
// } Driver Code Ends