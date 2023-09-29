// Minimum Operations to Reduce X to Zero

/*
sum(3, 4, 7, 1, 3, 8, 2, 4) = sum(4, 7, 1, 3, 8) + sum(3, 2, 4)
sum(3, 4, 7, 1, 3, 8, 2, 4) = sum(4, 7, 1, 3, 8) + x
sum(3, 4, 7, 1, 3, 8, 2, 4) - x = sum(4, 7, 1, 3, 8) 
23 = sum(4, 7, 1, 3, 8) 
*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        for (int num : nums) target += num;
        target -= x;
        
        if (target == 0) return n;
        
        int max_len = 0, cur_sum = 0, left = 0;
        
        for (int right = 0; right < n; ++right) 
        {
            cur_sum += nums[right];
            while (left <= right && cur_sum > target) 
            {
                cur_sum -= nums[left];
                left++;
            }
            if (cur_sum == target)
            {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len ? n - max_len : -1;
    }
};