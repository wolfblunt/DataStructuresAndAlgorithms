// Maximize median after doing k addition operation : O(n*log(n))

class Solution {
  public:
    bool isMidCanBecomeMedian(vector<int>& arr, int mid, int k)
    {
        int value = 0;
        int n = arr.size();
        int half = n/2;
        if(n%2==1) // Odd Case
        {
            value += max(0, mid-arr[half]);
        }
        else // Even Case
        {
            value += max(0, 2*mid-arr[half]-arr[half-1]);
        }
        
        for(int i=half+1;i<n;i++)
        {
            value += max(0, mid-arr[i]);
            if(value>k)
            {
                return false;
            }
        }
        
        return (value <= k);
    }
  
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 0;
        int high = arr[n-1]+k;
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isMidCanBecomeMedian(arr, mid, k))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};