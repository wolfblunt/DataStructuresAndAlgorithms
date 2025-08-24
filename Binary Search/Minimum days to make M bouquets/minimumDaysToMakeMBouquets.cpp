// Minimum days to make M bouquets: O(n*log(n))

class Solution {
  public:
    bool helper(vector<int>& arr, int day, int m, int k)
    {
        int count = 0;
        int bouquet=0;
        for(auto a: arr)
        {
            if(a<=day)
            {
                count++;
                if(count==k)
                {
                    count=0;
                    bouquet++;
                }
            }
            else
            {
                count=0;
            }
        }
        
        return bouquet>=m;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if(m*k > n)
        {
            return -1;
        }
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int total_flowers = m*k;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(helper(arr, mid, m, k))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};