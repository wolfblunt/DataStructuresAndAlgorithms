// Largest Sum Subarray of Size at least K

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int sum = 0, sum2 = 0, ans = LLONG_MIN;

        int j = 0;
        for(int i = 0; i < n; ++i) 
        {
            sum += a[i];
            if(i-j+1>=k) 
            {
                sum -= a[j];
                if(sum2 < 0)
                {
                    sum2 = 0;
                }
                sum2 += a[j++];
                ans = max(ans, sum + sum2);
            }
        }
        
        return ans;
    }
};