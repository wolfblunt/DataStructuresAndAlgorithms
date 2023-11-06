// Partition to K Equal Sum Subsets

class Solution {
public:
    bool helper(vector<int>& nums, vector<int> &visited, int &k, int partitionRemaining, int index, int partitionLength)
    {
        if(partitionRemaining == 0)
        {
            return true;
        }

        if(partitionLength == k)
        {
            return helper(nums, visited, k, partitionRemaining-1, 0, 0);
        }

        for(int i=index; i<nums.size();i++)
        {
            if (!visited[i])
            {
                visited[i] = true;

                if(helper(nums, visited, k, partitionRemaining, i+1, partitionLength+nums[i]))
                {
                    return true;
                }
                visited[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(auto a: nums)
        {
            sum += a;
        }

        if(nums.size() < k || sum%k)
        {
            return false;
        }

        vector<int> visited(n, false);
        int target = sum/k;
        return helper(nums, visited, target, k-1, 0, 0);
    }
};