//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B){
        
        int i=0;
        int j=0;
        stack<int> s;
        while(j<n)
        {
            while(i<n && (s.empty() || s.top()!=B[j]))
            {
                s.push(A[i]);
                i++;
            }
            while(!s.empty() && s.top() == B[j])
            {
                s.pop();
                j++;
            }
            if(i==n && !s.empty() && s.top()!=B[j])
            {
                return 0;
            }
        }
        
        return 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends