class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int noOfones=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                noOfones++;
        }
        // if(noOfones==0)
        // {
        //     return -1;
        // }
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int answer = n;
        int i = 0;
        int ones = 0;
        for(int j=0;j<2*n;j++)
        {
            if(nums[j]==1)
                ones++;
            
            if(j-i+1 == noOfones)
            {
                answer = min(answer, noOfones-ones);
                if(nums[i]==1)
                {
                    ones--;
                }
                i++;
            }
        }
        return answer == n ? 0:answer;
    }
};