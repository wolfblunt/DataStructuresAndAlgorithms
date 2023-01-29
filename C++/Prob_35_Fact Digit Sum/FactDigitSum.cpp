//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    vector<int> fact;
	    vector<int> digit;
	    fact.push_back(1);
	    for(int i=1;i<10;i++)
	    {
	        fact.push_back(i*fact[i-1]);
	    }
	    
	    for(int i=9;i>=1;i--)
	    {
	        while(N>=fact[i])
	        {
	            N = N - fact[i];
	            digit.push_back(i);
	        }
	    }
	    reverse(digit.begin(), digit.end());
	    return digit;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends