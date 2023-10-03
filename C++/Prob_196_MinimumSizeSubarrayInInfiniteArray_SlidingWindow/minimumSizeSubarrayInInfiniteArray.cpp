// Minimum Size Subarray in Infinite Array - Sliding Window

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long allSum = 0;
        for(int i=0;i<n;i++)
        {
            allSum += nums[i];
        }

        int q = target/allSum;
        int r = target % allSum;
        if(r==0)
        {
            return q*n;
        }

        target = r;

        vector<int> newNum(nums.begin(), nums.end());

        for(int i=0;i<n;i++)
        {
            newNum.push_back(nums[i]);
        }

        int j=0;
        long long sum = 0;
        int minLen = 1e9;
        for(int i=0;i<2*n;i++)
        {
            sum += newNum[i];
            while(sum > target)
            {
                sum -= newNum[j];
                j++;
            }
            if(sum == target)
            {
                minLen = min(minLen, i-j+1);
            }
        }
        
        if(minLen != 1e9)
        {
            return (q*n+minLen);
        }
        return -1;
    }
};