// Maximize the minimum difference between k elements - (n*log(n))

class Solution {
  public:
    int helper(vector<int>& arr, int mid, int k)
    {
        int count = 1;
        int left = 0;
        int n = arr.size();
        for(int right=1;right<n;right++)
        {
            if(arr[right]-arr[left] >= mid)
            {
                count++;
                left=right;
            }
        }
        
        return count>=k;
    }
  
  
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n-1]-arr[0];
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(helper(arr, mid, k))
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};