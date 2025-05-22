// Zero Array Transformation II - O(N∗Log(N))

class Solution {
public:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        int sum = 0;
        vector<int> differenceArray(n + 1);

        for (int queryIndex = 0; queryIndex < k; queryIndex++) 
        {
            int start = queries[queryIndex][0];
            int end = queries[queryIndex][1];
            int val = queries[queryIndex][2];

            differenceArray[start] += val;
            differenceArray[end + 1] -= val;
        }

        for (int numIndex = 0; numIndex < n; numIndex++) 
        {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex])
            {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        if(!canFormZeroArray(nums, queries, n))
        {
            return -1;
        }
        
        int low = 0;
        int high = n;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(canFormZeroArray(nums, queries, mid))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};