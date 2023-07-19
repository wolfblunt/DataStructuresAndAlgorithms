// Longest Alternating Subarray - Brute Force : O(n^2)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxl = -1;
        for(int i=0;i<n-1;i++)
        {
            int l = 1;
            int flag = 1;
            for(int j=i+1;j<n;j++)
            {
                if(flag%2)
                {
                    if(nums[j] - nums[j-1] == 1)
                    {
                        l++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {  
                    if(nums[j] - nums[j-1] == -1)
                    {
                        l++;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                flag++;
            }
            maxl = max(maxl, l);
        }
        return maxl==1?-1:maxl;
    }
};