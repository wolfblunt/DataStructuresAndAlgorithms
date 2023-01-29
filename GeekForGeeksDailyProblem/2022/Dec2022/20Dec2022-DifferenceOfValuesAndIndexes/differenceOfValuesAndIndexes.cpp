// difference of values and indexes
#include <bits/stdc++.h> 
using namespace std; 


class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int sum=0;
        int cond1=INT_MIN;
        int cond2=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            cond1 = max(cond1, -arr[i]+i);
            cond2 = max(cond2, arr[i]+i);
            sum = max(sum, max(arr[i]+cond1-i, cond2-arr[i]-i));
        }
        return sum;
    } 
};

int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 