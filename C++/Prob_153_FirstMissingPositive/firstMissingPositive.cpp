// First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int element = nums[i];
            if(element>0 && element<=n)
            {
                int chair = element - 1;
                if(nums[chair]!=element)
                {
                    swap(nums[i], nums[chair]);
                    i--;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }

        return n+1;
    }
};