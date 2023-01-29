//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<long long> preSmall(long long int* arr,int n){
       vector<long long> left;
        stack< pair<long long,long long>> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
       return left;
   }
   
   vector<long long> postSmall(long long int* arr,int n){
       vector<long long> right;
        stack< pair<long long,long long>> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right.push_back(n);
            }
            else{
                right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
       reverse(right.begin(),right.end());
       return right;
   }
   
   //Function to find largest rectangular area possible in a given histogram.
   long long getMaxArea(long long arr[], int n)
   {
       // Your code here
       vector<long long> left;
       vector<long long> right;
       left = preSmall(arr,n);
       right = postSmall(arr,n);
       
        long long area;
       for(int i=0;i<n;i++){
            long long temp = (right[i]-left[i]-1)*arr[i];
            area = max(area, temp);
       }
       
       return area;
   }
    
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends