// Find Indices With Index and Value Difference II

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxi = nums[0];
        int mini = nums[0];
        int a = 0;
        int b = 0;
        int n = nums.size();
        for(int i=indexDifference;i<n;i++)
        {
            if(nums[i-indexDifference] > maxi)
            {
                maxi = nums[i-indexDifference];
                a = i - indexDifference;
            }
            
            if(nums[i-indexDifference] < mini)
            {
                mini = nums[i-indexDifference];
                b = i - indexDifference;
            }
            
            if(abs(nums[i] - maxi) >= valueDifference)
            {
                return {a,i};
            }
            
            if(abs(nums[i] - mini) >= valueDifference)
            {
                return {b,i};
            }
        }
        
        return {-1,-1};
    }
};