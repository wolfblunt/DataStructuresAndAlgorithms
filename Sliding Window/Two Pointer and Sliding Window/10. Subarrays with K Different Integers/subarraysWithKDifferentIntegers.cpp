// Subarrays with K Different Integers - O(n)

class Solution {
public:
    int subarrayLessThanEqualKDistinct(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> um;
        int left = 0, right = 0;
        int count = 0;
        for(;right<n;right++)
        {
            um[nums[right]]++;

            while(um.size() > k)
            {
                um[nums[left]]--;
                if(um[nums[left]] == 0)
                {
                    um.erase(nums[left]);
                }
                left++;
            }

            count += (right-left+1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayLessThanEqualKDistinct(nums, k) - subarrayLessThanEqualKDistinct(nums, k-1);
    }
};