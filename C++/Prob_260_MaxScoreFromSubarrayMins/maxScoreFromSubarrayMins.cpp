// Max Score from Subarray Mins - O(n)

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int ans = 0;
        int n = arr.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] + arr[i+1] > ans)
            {
                ans = arr[i] + arr[i+1];
            }
        }
        
        return ans;
    }
};