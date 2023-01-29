// Burst Balloons
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int balloonBurst(int i, int j, vector<int> &arr, vector<vector<int>>& dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi=INT_MIN;
        for(int index=i; index<=j; index++)
        {
            int cost = arr[i-1]*arr[index]*arr[j+1] + balloonBurst(i, index-1, arr, dp) + balloonBurst(index+1, j, arr, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j]=maxi;
    }
    
    int maxCoins(int N, vector<int> &arr) {
        vector<vector<int>> dp(N+1, vector<int>(N+1,-1));
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        return balloonBurst(1,N, arr, dp);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}