#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        sort(capacity.begin(), capacity.end());
        long long int answer=1;
        long long int mod = 1e9 + 7;  //1000000007
        for(int i=0;i<n;i++)
        {
            answer*=(capacity[i]-i);
            answer %= mod;
        }
        return int(answer);
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}