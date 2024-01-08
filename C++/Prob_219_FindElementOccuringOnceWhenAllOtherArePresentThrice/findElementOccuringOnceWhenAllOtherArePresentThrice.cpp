// Find element occuring once when all other are present thrice

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int ans = 0;
        for(int j=31;j>=0;j--)
        {
            int countBits = 0;
            for(int i=0;i<N;i++)
            {
                if((arr[i] >> j) & 1)
                {
                    countBits++;
                }
            }
            if(countBits % 3)
            {
                ans = ans ^ (1<<j);
            }
        }
        
        return ans;
    }
};