// Time Complexity: O(nlogn)

#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int>ans;
        ans.push_back(a[0]);
        for(int i = 1;i<n;i++)
        {
            auto it = lower_bound(ans.begin(),ans.end(),a[i]);
            if(it == ans.end())
            {
                ans.push_back(a[i]);
            }
            else{
                ans[it - ans.begin()] = a[i];
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends