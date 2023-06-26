// Ways to Split Array Into Good Subarrays

class Solution {
public:
    long long mod = 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;
        int zeroCount = 0;
        long long ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zeroCount++;
            }
            else
            {
                onesCount++;
                if(onesCount==1)
                {
                    ans = 1;
                }
                else
                {
                    ans = (ans * (zeroCount+1) % mod) % mod;
                }
                zeroCount = 0;
            }
        }
        
        return ans % mod;
    }
};