// Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m-1;
        int j = n-1;

        while(i>=0 && j>=0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[i+j+1] = nums1[i];
                i--;
            }
            else
            {
                nums1[i+j+1] = nums2[j];
                j--;
            }
        }

        // for test case: nums1=[0], m = 0, nums2=[1], n=1
        while(j>=0)   
        {
            nums1[j] = nums2[j];
            j--;
        }
    }
};