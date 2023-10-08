// OR SUM
// https://www.youtube.com/watch?v=KSHIJl5EDrs&ab_channel=GeeksforGeeksPractice - Q3

class Solution{
    public:
    int orSum(int n, vector<int> A, int m, vector<int> B){
        long long mod = 1e9+7;
        vector<long long> c1(30,0);
        vector<long long> c2(30,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<30;j++)
            {
                c1[j]+=(A[i]%2);
                A[i] = A[i]/2;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<30;j++)
            {
                c2[j]+=(B[i]%2);
                B[i] = B[i]/2;
            }
        }
        
        long long ans = 0;
        for(int i=0;i<30;i++)
        {
            ans = ans + (((c1[i]*c2[i] + c1[i]*(m-c2[i]) + (n-c1[i])*c2[i])%mod) * (1<<i) % mod);
            ans = ans%mod;
        }
        
        return ans;
    }
};