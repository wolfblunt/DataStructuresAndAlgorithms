// Count the subarrays having product less than k  - Sliding Window : O(n)

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long mulVal = 1;
        int noOfSubarray = 0;
        int startIdx = 0, endIdx = 0;
        
        while(endIdx < n)
        {
            mulVal *= a[endIdx];
            while(startIdx < n && mulVal >= k)
            {
                mulVal = mulVal/a[startIdx];
                startIdx++;
            }
            
            if(mulVal < k)
            {
                noOfSubarray += endIdx - startIdx  + 1;
            }
            endIdx++;
        }
        
        return noOfSubarray;
    }
};