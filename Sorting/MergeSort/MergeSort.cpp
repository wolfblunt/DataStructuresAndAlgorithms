// MergeSort: O(n*log(n))

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> a(n1);
        vector<int> b(n2);

        for(int i=0;i<n1;i++)
        {
            a[i] = nums[low + i];
        }

        for(int j=0;j<n2;j++)
        {
            b[j] = nums[mid+1 + j];
        }

        int i = 0;
        int j = 0;
        int k = low;
        
        while(i<n1 && j<n2)
        {
            if(a[i] <= b[j])
            {
                nums[k] = a[i];
                i++;
                k++;
            }
            else
            {
                nums[k] = b[j];
                j++;
                k++;
            }
        }

        while(i<n1)
        {
            nums[k] = a[i];
            k++;
            i++;
        }

        while(j<n2)
        {
            nums[k] = b[j];
            j++;
            k++;
        }
    }


    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low<high)
        {
            int mid = low + (high-low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};