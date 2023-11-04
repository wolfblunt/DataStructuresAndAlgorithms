// Sum of XOR of all pairs - O(32*n)

class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long long ans = 0;
    	for(int i=0;i<=31;i++)
    	{
    	    long long nOnes = 0;
    	    long long nZero = 0;
    	    for(int j=0;j<n;j++)
    	    {
    	        if(arr[j] & (1<<i))
    	        {
    	            nOnes++;
    	        }
    	        else
    	        {
    	            nZero++;
    	        }
    	    }
    	    
    	    ans += nOnes*nZero*(1<<i); // contribution of that particular index in the overall Xor Sum
    	}
    	
    	return ans;
    }
};