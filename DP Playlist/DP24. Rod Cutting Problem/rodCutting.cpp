// Rod Cutting

#include <bits/stdc++.h>
using namespace std;



class Solution{
  public:
    int helper(int price[], int index, int n, vector<vector<int>> &dp)
    {
        if(index==0)
        {
            return n*price[index];
        }
        if(dp[index][n]!=-1)
        {
            return dp[index][n];
        }
        int notPick = 0 + helper(price, index-1, n, dp);
        int pick = INT_MIN;
        int rodLength = index+1;
        if(rodLength<=n)
        {
            pick = price[index] + helper(price, index, n-rodLength, dp);
        }
        return dp[index][n] = max(pick, notPick);
    }
    
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,-1));  // dp[index][rodLength]
        return helper(price, n-1, n, dp);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}