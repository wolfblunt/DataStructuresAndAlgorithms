// Distinct Coloring

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long long int dpColoring(int index, int N, int r[], int g[], int b[], int previous, vector<vector<long long int>>& dp)
    {
        if(index==N)
            return 0;
        
        if(dp[index][previous]!=-1)
            return dp[index][previous];
        
        long long int pick_R = LLONG_MAX; // or 1e11
        long long int pick_G = LLONG_MAX;
        long long int pick_B = LLONG_MAX;
        if(previous==0) // If no color painted
        {
            pick_R = r[index] + dpColoring(index+1,N,r,g,b,1,dp);
            pick_G = g[index] + dpColoring(index+1,N,r,g,b,2,dp);
            pick_B = b[index] + dpColoring(index+1,N,r,g,b,3,dp);
        }
        
        else if(previous==1) // If red color painted
        {
            pick_G = g[index] + dpColoring(index+1,N,r,g,b,2,dp);
            pick_B = b[index] + dpColoring(index+1,N,r,g,b,3,dp);
        }
        
        else if(previous==2) // If Green Color painted
        {
            pick_R = r[index] + dpColoring(index+1,N,r,g,b,1,dp);
            pick_B = b[index] + dpColoring(index+1,N,r,g,b,3,dp);
        }
        
        else if(previous==3) // If Blue Color painted
        {
            pick_R = r[index] + dpColoring(index+1,N,r,g,b,1,dp);
            pick_G = g[index] + dpColoring(index+1,N,r,g,b,2,dp);
        }
        
        return dp[index][previous] = min(pick_R, min(pick_G, pick_B));
    }
    
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> dp(N, vector<long long int>(4,-1));
        // 0 -> no color
        // 1 -> red color
        // 2 -> green color
        // 3 -> blue color
        return dpColoring(0,N,r,g,b,0,dp);
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}