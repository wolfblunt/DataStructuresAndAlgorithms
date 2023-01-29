// Maximum Sum Circular Subarray

class Solution {
public:
    int kadaneAlgo(vector<int>& nums, int n)
    {
        int sum = nums[0];
        int temp = 0;
        for(int i=0;i<n;i++)
        {
            temp += nums[i];
            sum = max(sum, temp);
            if(temp<0)
                temp = 0;
        }
        return sum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int nonCircularSum = kadaneAlgo(nums, n);
        for(int i=0;i<n;i++)
        {
            totalSum+=nums[i];
            nums[i] = -nums[i];
        }

        int minimumSum = kadaneAlgo(nums, n);
        int maxSum = totalSum + minimumSum;
        if(maxSum==0)
            return nonCircularSum;
        return max(maxSum, nonCircularSum);
    }
};