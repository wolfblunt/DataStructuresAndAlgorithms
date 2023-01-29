//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        map<pair<int,int>, int> m;
        
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sum = A[i] + A[j]; 
                m[{i,j}] = sum;
            }
        }
        
        
        for(auto a: m)
        {
            for(auto b:m)
            {
                if(a.second==b.second && a.first.first!=b.first.first && a.first.first!=b.first.second && a.first.second!=b.first.first && a.first.second!=b.first.second)
                {
                    return {a.first.first, a.first.second, b.first.first, b.first.second};
                }
            }
        }
        
        return {-1,-1,-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends