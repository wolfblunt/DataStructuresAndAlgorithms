#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9+7;
	public:
		int CountWays(string str){
		    int n = str.length();
		    vector<int> dp(n);
		    dp[0] = 1;
		    for(int i=1;i<n;i++)
		    {
		        if(str[i-1]=='0' && str[i]=='0')
		        {
		            dp[i] = 0;
		        }
		        else if(str[i-1]=='0' && str[i]!='0')
		        {
		            dp[i] = dp[i-1]%mod;
		        }
		        else if(str[i-1]!='0' && str[i]=='0')
		        {
		            if(str[i-1]=='1' || str[i-1]=='2')
		            {
		                dp[i] = ((i>=2) ? dp[i-2]%mod : 1);
		            }
		            else
		            {
		                dp[i] = 0;
		            }
		        }
		        else
		        {
		            if(stoi(str.substr(i-1,2)) <= 26)
		            {
		                dp[i] = dp[i-1]%mod + ((i>=2) ? dp[i-2]%mod : 1);
		            }
		            else
		            {
		                dp[i] = dp[i-1]%mod;
		            }
		        }
		    }
		    return dp[n-1]%mod;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}