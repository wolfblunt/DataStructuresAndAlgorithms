// Permutations

class Solution {
public:
    void swap(vector<int> &nums, int l, int r)
    {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }

    void helperFunc(vector<int>& nums, int index, vector<vector<int>> &result)
    {
        if(nums.size() == index)
        {
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums, i, index);
            helperFunc(nums, index+1, result);
            swap(nums, i, index);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helperFunc(nums, 0, result);
        return result;
    }
};