#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int r;
        r = (n) & ~(n-1);
        for(int i=0;i<32;i++)
        {
            if(r==0)
            {
                return i;
            }
            r=r>>1;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends