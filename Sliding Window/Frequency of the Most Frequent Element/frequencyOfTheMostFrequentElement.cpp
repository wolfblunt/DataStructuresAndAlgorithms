// Frequency of the Most Frequent Element

// Sliding Window - O(nlogn)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long j = 0;
        long long ans = 0, sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            while((i-j+1)*nums[i] - sum > k)
            {
                sum -= nums[j];
                j++;
            }
            ans = max(ans, i-j+1);
        }

        return ans;
    }
};