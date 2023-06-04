// Semi-Ordered Permutation

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 1 && nums[n-1] == n)
        {
            return 0;
        }
        
        int min_i = 0;
        int max_i = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                min_i = i;
            }
            if(nums[i]==n)
            {
                max_i = i;
            }
        }
        
        int result = 0;
        if(max_i < min_i)
        {
            result =  n - 1 - max_i + min_i - 1;
        }
        else
        {
            result =  n - 1 - max_i + min_i;
        }
        return result;
    }
};