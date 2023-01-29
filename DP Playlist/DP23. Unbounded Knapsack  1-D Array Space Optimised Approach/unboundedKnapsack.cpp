// Unbounded Knapsack

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int infiniteKnapSack(int value[], int index, int wt[], int weight, vector<vector<int>> &dp)
    {
        if(index==0)
        {
            return (weight/wt[index])*value[index];
        }
        if(dp[index][weight]!=-1)
        {
            return dp[index][weight];
        }
        
        int notPick = 0 + infiniteKnapSack(value, index-1, wt, weight, dp);
        int pick = INT_MIN;
        if(wt[index]<=weight)
        {
            pick = value[index] + infiniteKnapSack(value, index, wt, weight-wt[index], dp);
        }
        return dp[index][weight] = max(pick, notPick);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1,-1));
        return infiniteKnapSack(val, N-1, wt, W, dp);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}