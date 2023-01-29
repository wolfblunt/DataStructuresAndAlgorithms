//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins{1,2,5,10,20,50,100,200,500,2000}; 
        vector<int> result;
        while(N>0)
        {
            int coinIndex = lower_bound(coins.begin(), coins.end(), N) - coins.begin();   // binary Search
            if(coins[coinIndex] != N)
            {
                coinIndex = coinIndex- 1;
            }
            int coinValue = coins[coinIndex];
            result.push_back(coinValue);
            N = N - coinValue;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends