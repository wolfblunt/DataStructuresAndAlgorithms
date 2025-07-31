// Binary Subarrays With Sum - O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        for(;right<n;right++)
        {
            sum += nums[right];
            while(left<=right && sum>goal)
            {
                sum -= nums[left];
                left++;
            }
            count += (right-left+1);
        }

        cout<<"count: "<<count<<endl;
        
        left=0;
        right=0;
        int count2 = 0;
        sum = 0;
        for(;right<n;right++)
        {
            sum += nums[right];
            while(left<=right && sum>=goal)
            {
                sum -= nums[left];
                left++;
            }
            count2 += (right-left+1);
        }

        cout<<"count2: "<<count2<<endl;
        return count-count2;
    }
};