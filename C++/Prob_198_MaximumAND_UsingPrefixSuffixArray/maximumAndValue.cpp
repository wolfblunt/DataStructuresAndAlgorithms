// Maximum AND Value

class Solution{
    public:
    int maxAnd(int N, vector<int> A){
        vector<int> suffix(N);
        suffix[N-1] = A[N-1];
        for(int i=N-2;i>=0;i--)
        {
            suffix[i] = A[i] & suffix[i+1];
        }
        
        vector<int> prefix(N);
        prefix[0] = A[0];
        for(int i=1;i<N;i++)
        {
            prefix[i] = A[i] & prefix[i-1];
        }
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            int maxi = INT_MAX;
            if(i==0)
            {
                maxi = maxi & suffix[i+1];
            }
            else if(i==N-1)
            {
                maxi = maxi & prefix[i-1];
            }
            else
            {
            	// let a[i] = INT_MAX - let all the values are ones for that particular a[i] - maxValue
            	// prefix[i-1] & a[i] & suffix[i+1] - gives the value if we make that particular array index value maximum
                maxi = maxi & prefix[i-1];
                maxi = maxi & suffix[i+1];
            }
            
            ans = max(ans, maxi);
        }
        
        return ans;
    }
};