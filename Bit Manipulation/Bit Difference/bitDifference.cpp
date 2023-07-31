// Bit Difference : O(32*n)

// User function Template for C++

class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        long long ans = 0;
        long long mod = (int)1e9+7;
        for(int i=0;i<=31;i++)
        {
            long long count = 0;
            for(int j=0;j<n;j++)
            {
                if((1<<i) & arr[j])
                {
                    count++;
                }
            }
            ans = ans%mod + (count*(n-count)*2)%mod;
        }
        return ans%mod;
    }
};