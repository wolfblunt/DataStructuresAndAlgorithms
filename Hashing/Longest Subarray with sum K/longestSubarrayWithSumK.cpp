// Longest Subarray with Sum K - O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> um;
        int maxlen = 0;
        int prefixSum = 0;
        
        for(int i=0;i<n;i++)
        {
            prefixSum += arr[i];
            if(prefixSum == k)
            {
                maxlen = max(maxlen, i+1);
            }
            if(um.find(prefixSum - k) != um.end())
            {
                maxlen = max(maxlen, i-um[prefixSum-k]);
            }
            if(um.find(prefixSum) == um.end())
            {
                um[prefixSum] = i;
            }
        }
        
        return maxlen;
    }
};