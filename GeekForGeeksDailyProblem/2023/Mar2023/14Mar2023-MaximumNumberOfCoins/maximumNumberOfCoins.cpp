// Maximum Number Of Coins

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int dpSolve(vector<int> &a, int i, int j, vector<vector<int>> &dp, int l, int h){
            // l = lower boundary ballon value h = higher boundary balllon value
            if(i > j)
                return 0;
            if(dp[i][j] != -1)
                return dp[i][j];
            for(int k=i;k<=j;k++){
                dp[i][j] = max(dp[i][j], l*h*a[k] + dpSolve(a, i, k-1, dp, l, a[k])+
 dpSolve(a, k+1, j, dp, a[k], h));
            }
            return dp[i][j];
            
        }
        int maxCoins(int N, vector <int> &a)
        {
                vector<vector<int>> dp(N,vector<int>(N,-1));
                return dpSolve(a,0,N-1, dp, 1,1);
        }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}