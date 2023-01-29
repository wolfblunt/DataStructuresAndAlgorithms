// Count Subsets with Sum K

// Memoization
int f(int i, int k, vector<int>& nums, vector<vector<int>>& dp){
    if(i==0){
        if(k==0 && nums[0]==0) return 2;
        if(k==0 || k==nums[0]) return 1;
        return 0;
    }
    if(dp[i][k]!=-1) return dp[i][k];
    int pick=0;
    if(k>=nums[i]) pick=f(i-1,k-nums[i],nums,dp);
    int notPick=f(i-1,k,nums,dp);
    return dp[i][k]=pick+notPick;
}


// tabulation:
int tabulation(int n, int target, vector<int>& nums){
    vector<vector<int>> dp(n,vector<int>(target+1));
    if(nums[0]<=target) dp[0][nums[0]]=1;
    if(nums[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    
    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            int pick=0;
            if(k>=nums[i]) pick=dp[i-1][k-nums[i]];
            int notPick=dp[i-1][k];
            dp[i][k]=pick+notPick;
        }
    }
    return dp[n-1][target];
}

// Space Optimization:
int spaceOptimization(int n, int target, vector<int>& nums){
    vector<int> prev(target+1), cur(target+1);
    if(nums[0]<=target) prev[nums[0]]=1;
    if(nums[0]==0) prev[0]=2;
    else prev[0]=1;
    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            int pick=0;
            if(k>=nums[i]) pick=prev[k-nums[i]];
            int notPick=prev[k];
            cur[k]=pick+notPick;
        }
        prev=cur;
    }
    return prev[target];
}



int findWays(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,nums,dp); // memoization
//     return tabulation(n,k,nums); // tabulation
//     return spaceOptimization(n,k,nums); // space Optimization
}