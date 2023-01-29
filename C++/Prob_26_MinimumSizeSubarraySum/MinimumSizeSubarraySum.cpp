// the sum is greater than or equal to target
class Solution {
public:
    int minSubArrayLen(int sum, vector<int>& nums) {
        int curr_sum=0;
        int answer = INT_MAX;
        int n = nums.size();
        int left=0;
        int right=0;
        for(right=0;right<n;right++)
        {
            curr_sum+=nums[right];
            while(curr_sum>=sum)
            {
                answer = min(answer, right-left+1);
                curr_sum-=nums[left++];
            }
        }
        return answer==INT_MAX?0:answer;
        
    }
};

//Input : 11
//[1,2,3,4,5]

// Output : 3 => [3,4,5] [12>11]