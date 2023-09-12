// Maximum Beauty of an Array After Applying Operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> freq(3e5+2, 0);
        int offset = 1e5;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int start = nums[i]-k;
            int end = nums[i]+k;
            freq[offset + start]++;
            freq[offset + end + 1]--;
        }

        int maxx = freq[0];
        for(int i=1;i<300002;i++)
        {
            freq[i] += freq[i-1];
            maxx = max(maxx, freq[i]);
        }
        return maxx;
    }
};