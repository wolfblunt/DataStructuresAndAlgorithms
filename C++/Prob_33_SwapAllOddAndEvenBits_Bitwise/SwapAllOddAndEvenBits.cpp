//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	vector<int> bits;
    	while(n)
    	{
    	    bits.push_back(n%2);
    	    n=n>>1;
    	}
    	
    	if(bits.size() & 1)
    	{
    	    bits.push_back(0);
    	}
    	
    	for(int i=0;i<bits.size();i+=2)
    	{
    	    swap(bits[i],bits[i+1]);
    	}
    	
    	n=0;
    	
    	for(int i=0;i<bits.size();i++)
    	{
    	    n+=bits[i]*pow(2,i);
    	}
    	return n;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends