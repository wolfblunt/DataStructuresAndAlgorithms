// Longest Subarray with Majority Greater than K - O(N)

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int prefixSum = 0;
        int n = arr.size();
        unordered_map<int, int> um;
        um[0] = -1;
        int maxlen = 0;
        for(int i=0;i<n;i++)
        {
            prefixSum += arr[i] > k ? 1 : -1;
            if(prefixSum > 0)
            {
                maxlen = max(maxlen, i+1);
            }
            if(um.find(prefixSum - 1) != um.end())
            {
                maxlen = max(maxlen, i-um[prefixSum-1]);
            }
            if(um.find(prefixSum) == um.end())
            {
                um[prefixSum] = i;
            }
        }
        return maxlen;
    }
};