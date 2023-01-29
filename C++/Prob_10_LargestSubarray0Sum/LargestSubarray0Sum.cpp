//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int curr_sum = 0;
        int sum = 0;
        int start = 0;
        int end;
        int length = 0;
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            curr_sum += A[i];
            if(curr_sum - sum ==0)
            {
                start = 0;
                end = i;
                length = max(length, end) + 1;
                m[curr_sum] = i;
            }
            if(!m.count(curr_sum-sum))
            {
                m[curr_sum] = i;
            }
            else{
                auto it = m.find(curr_sum-sum);  
                start = it->second;
                //start = map.get(curr_sum-sum); 
                end = i;
                int temp = end-start;
                length = max(temp, length);
            }
        }
        return length;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends