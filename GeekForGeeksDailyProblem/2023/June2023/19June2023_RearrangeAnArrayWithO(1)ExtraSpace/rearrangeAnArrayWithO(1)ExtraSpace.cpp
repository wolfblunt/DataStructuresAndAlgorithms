// Rearrange an array with O(1) extra space

#include<bits/stdc++.h>
using namespace std;


   
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i] / n;
        }
    }
};



int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}