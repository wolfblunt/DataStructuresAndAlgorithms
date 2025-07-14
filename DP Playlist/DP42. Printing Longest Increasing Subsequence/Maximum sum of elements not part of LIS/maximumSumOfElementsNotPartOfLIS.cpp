// Maximum sum of elements not part of LIS - O(n^2)

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int total = 0;
        int maxi = 1;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            total+=arr[i];
            for(int j=0;j<i;j++)
            {
                if(arr[i] > arr[j] && dp[i] <= dp[j]+1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            
            if(maxi <= dp[i])
            {
                maxi = dp[i];
                index = i;
            }
        }
        
        int sum = arr[index];
        
        while(hash[index] != index)
        {
            index = hash[index];
            sum += arr[index];
        }
        
        return total-sum;
    }
};