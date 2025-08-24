// Farthest Smaller Right - O(N*log(N))

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix(n);
        suffix[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[suffix[i+1]] <= arr[i])
            {
                suffix[i] = suffix[i+1];
            }
            else
            {
                suffix[i] = i;
            }
        }
        
        
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++)
        {
            int low = i+1;
            int high = n-1;
            
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                
                if(arr[suffix[mid]] < arr[i])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            if(high != i)
            {
                ans[i] = high;
            }
        }
        
        return ans;
    }
};