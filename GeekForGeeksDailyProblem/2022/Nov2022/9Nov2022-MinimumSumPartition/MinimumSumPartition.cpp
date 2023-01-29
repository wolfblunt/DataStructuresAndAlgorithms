#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
    int findRecursiveDiff(int *&arr, int i,int n, int s1, int s2, vector<vector<int>>& dp)
    {
        if(i==n)
        {
            int diff = abs(s1-s2);
            return diff;
        }
        
        if(dp[i][abs(s1-s2)] != -1)
        {
            return dp[i][abs(s1-s2)];
        }
        
        int pickIns1 = findRecursiveDiff(arr, i+1, n,s1+arr[i],s2,dp);
        int pickIns2 = findRecursiveDiff(arr, i+1, n,s1,s2+arr[i],dp);
        
        return dp[i][abs(s1-s2)] = min(pickIns1, pickIns2);
    }
    
	int minDifference(int arr[], int n)  { 
	    int totalSum = 0;
        for(int i=0;i<n;i++)totalSum+=arr[i];
	    vector<vector<int>> dp(n+1, vector<int>(totalSum+1,-1));
	    
	    int s1=0;
	    int s2=0;
	    
	    return findRecursiveDiff(arr, 0, n, s1, s2, dp);
	} 
};


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}