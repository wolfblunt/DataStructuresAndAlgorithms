// Sum of Products - O(32*n)

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long ans = 0;
        for(int i=0;i<=31;i++)
        {
            long long count = 0;
            long long temp = 1<<i;
            
            for(int j=0;j<n;j++)
            {
                if(arr[j] & temp)
                {
                    count++;
                }
            }
            
            ans += (count*(count-1)/2) * temp; // nC2 - chossing 2 from n
        }
        
        return ans;
    }
};