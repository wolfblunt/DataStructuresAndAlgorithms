// Kth smallest element

class Solution{
    public:
    // nums : given array
    // l : starting index of the array i.e 0
    // n : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int nums[], int l, int n, int k) {
        priority_queue<int> pq;
        // int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};