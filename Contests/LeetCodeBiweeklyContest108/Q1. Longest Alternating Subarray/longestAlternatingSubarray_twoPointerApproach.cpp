// Longest Alternating Subarray : O(n)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int front = 1, back=0;
        int state = INT_MAX;
        int ans = 0;
        int n = nums.size();

        while(front < n)
        {
            int diff  = nums[front] - nums[front-1];
            if(diff == (-1)*state)
            {
                state = state * (-1);
                ans = max(ans, front-back+1);
            }
            else
            {
                if(diff==1)
                {
                    state = diff;
                    back = front-1;
                    ans = max(ans, 2);
                }
                else
                {
                    state = INT_MAX;
                }
            }

            front++;
        }
        return ans?ans:-1;
    }
};