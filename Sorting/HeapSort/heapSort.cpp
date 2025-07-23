// Heap Sort: O(n*log(n))

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i)
    {
        int largest = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;

        if(leftChild<n && nums[largest] < nums[leftChild])
        {
            largest = leftChild;
        }
        if(rightChild<n && nums[largest] < nums[rightChild])
        {
            largest = rightChild;
        }
        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    void buildHeap(vector<int>& nums, int n)
    {
        int startIndex = n/2-1; // index of last non-leaf node
        for(int i=startIndex;i>=0;i--)
        {
            heapify(nums, n, i);
        }
    }

    void heapSort(vector<int>& nums, int n)
    {
        buildHeap(nums, n);
        for(int i=n-1;i>=0;i--)
        {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums, n);
        return nums;
    }
};