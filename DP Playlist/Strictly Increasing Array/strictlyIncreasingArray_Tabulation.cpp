// Strictly Increasing Array

class Solution {
  public:

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int lis = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] && ((nums[i]-nums[j]) >= (i-j)))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    lis = max(lis, dp[i]);
                }
            }
        }
        
        return n-lis;
    }
};