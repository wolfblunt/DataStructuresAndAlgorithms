// Next Permutation
// Steps:
// 1. a[i] < a[i+1]
// 2. j = a.size()-1 and Loop till a[i] >= a[j] and do j--
// 3. swap(a,i,j)
// 4. reverse(a, i+1, a.size()-1)

// Time - O(n) and Space - O(1)

class Solution {
public:
    void swap(vector<int>& nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void reverse(vector<int>& nums, int i, int j)
    {
        while(i<j)
        {
            swap(nums, i++, j--);
        }
    }

    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return;
        }
        int i = nums.size() - 2;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }

        if(i>=0)
        {
            int j = nums.size() - 1;
            while(j>=0 && nums[i]>=nums[j])
            {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1, nums.size()-1);
    }
};