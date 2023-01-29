//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        if(N==0)
        {
           return "-1";
        }    
        string a = arr[0];
        int l = a.size();
        string result;
        for(int i=0;i<l;i++)
        {
            for(int j=1;j<N;j++)
            {
                int s_n=arr[j].size();
                if(s_n<=i || arr[j][i]!=a[i])
                {
                    if(result.empty())
                    {
                        return "-1";  
                    }
                    else{
                        return result;
                    }
                }
            }
            result.push_back(a[i]);
        }
        if(result.empty())
        {
            return "-1";  
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends