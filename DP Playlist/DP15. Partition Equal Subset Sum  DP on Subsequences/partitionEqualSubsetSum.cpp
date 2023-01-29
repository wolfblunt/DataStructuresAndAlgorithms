class Solution {
public:

    bool subsetSumToK(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
    {
        if(target==0)
        {
            return true;
        }
        if(index==0)
        {
            return arr[index]==target;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        bool notPick = subsetSumToK(arr, index-1, target, dp);
        bool pick = false;
        if(arr[index] <= target)
        {
            pick = subsetSumToK(arr, index-1, target - arr[index], dp);
        }
        return dp[index][target] = pick | notPick;
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return subsetSumToK(arr, n-1, target, dp);
    }
};