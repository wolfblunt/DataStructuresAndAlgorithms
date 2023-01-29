// Reverse Pairs

class Solution {
public:
    void merge(vector<int>& nums, int p, int q, int r)
    {
        int n1 = q-p+1;
        int n2 = r-q;
        vector<int> a(n1);
        vector<int> b(n2);
        for(int i=0;i<n1;i++)
        {
            a[i] = nums[p+i];
        }
        for(int j=0;j<n2;j++)
        {
            b[j] = nums[q+1+j];
        }
        int i=0,j=0,k=p;
        while(i<n1 && j<n2)
        {
            if(a[i]<= b[j])
            {
                nums[k] = a[i];
                k++;
                i++; 
            }
            else
            {
                nums[k] = b[j];
                k++;
                j++;
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
            k++;
            j++;
        }
    }

    int mergeSort(vector<int>& nums, int p, int r)
    {
        int inversion = 0;
        if(p<r)
        {
            int q = (p+r)/2;
            inversion += mergeSort(nums, p, q);
            inversion += mergeSort(nums, q+1, r);
            for(int i=p, j=q+1;i<=q;i++)
            {
                while(j<=r && nums[i] > 2LL*nums[j])
                {
                    j++;
                }
                inversion += j-(q+1);
            }
            merge(nums, p, q, r);
        }
        return inversion;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};