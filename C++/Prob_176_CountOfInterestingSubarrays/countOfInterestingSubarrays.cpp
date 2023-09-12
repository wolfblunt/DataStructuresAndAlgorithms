// Count of Interesting Subarrays

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long int ans = 0;
        long long int n = nums.size();
        for(long long int i=0;i<n;i++)
        {
            if(nums[i]%modulo == k)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }

        unordered_map<long long int, long long int> um;
        long long int total = 0;
        for(long long int i=0;i<n;i++)
        {
            total += nums[i];
            long long int modVal = total % modulo;
            if(modVal == k)
            {
                ans++;
            }
            long long int find = modVal - k;
            if(find < 0)
            {
                find += modulo;
            }
            ans += um[find];
            um[modVal]++;
        }

        return ans;
    }
};