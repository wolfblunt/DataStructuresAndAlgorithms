// Number of subarrays with maximum values in given range

class Solution{
    public:
    long countSubarrays(int arr[], int n, int L, int R)
    {
        int start = 0, end=0, ans=0, empire=0;   
        for(end=0;end<n;end++)
        {
            if(arr[end] >=L && arr[end] <= R)
            {
                empire = end-start+1;
            }
            if(arr[end] > R)
            {
                empire = 0;
                start = end+1;
            }
            ans += empire;
        }
    
        return ans;
    }
};