// Walls Coloring
#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int houseColoring(int index, int N, vector<vector<int>> &colors, int previous, vector<vector<int>>& dp)
    {
        if(index>=N)
            return 0;
        
        if(dp[index][previous]!=-1)
        {
            return dp[index][previous];
        }
        //p,b,y
        int pick_P = INT_MAX;
        int pick_B = INT_MAX;
        int pick_Y = INT_MAX;
        if(previous==0)
        {
            pick_P = colors[index][0] + houseColoring(index+1, N, colors, 1, dp);
            pick_B = colors[index][1] + houseColoring(index+1, N, colors, 2, dp);
            pick_Y = colors[index][2] + houseColoring(index+1, N, colors, 3, dp);
        }
        
        else if(previous==1)
        {
            pick_B = colors[index][1] + houseColoring(index+1, N, colors, 2, dp);
            pick_Y = colors[index][2] + houseColoring(index+1, N, colors, 3, dp);
        }
        
        else if(previous==2)
        {
            pick_B = colors[index][0] + houseColoring(index+1, N, colors, 1, dp);
            pick_Y = colors[index][2] + houseColoring(index+1, N, colors, 3, dp);
        }
        else if(previous==3)
        {
            pick_B = colors[index][0] + houseColoring(index+1, N, colors, 1, dp);
            pick_Y = colors[index][1] + houseColoring(index+1, N, colors, 2, dp);
        }
        
        return dp[index][previous] = min(pick_P, min(pick_B, pick_Y));
    }

    
    int minCost(vector<vector<int>> &colors, int N) {
        // 0 -> no color
        // 1 -> Pink color
        // 2 -> Black color
        // 3 -> Yellow color
        vector<vector<int>> dp(N, vector<int>(4, -1));
        return houseColoring(0,N,colors,0,dp);
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}