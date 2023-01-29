//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

bool valid(int i, int j, int n, int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

long long numOfWays(int N, int M)
{
    long long answer=0;
    long long mod=1e9+7;
    long long moves[8][2] = {{-2,-1},{-2,1},{-1,-2},{1,-2},{-1,2},{1,2},{2,1},{2,-1}};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            long long total = N*M;
            long long minus = 1;
            for(int k=0;k<8;k++)
            {
                if(valid(i+moves[k][0], j+moves[k][1], N, M))
                {
                    minus++;
                }
            }
            total-=minus;
            answer=(answer+total)%mod;
        }
    }
    
    return answer%mod;
}