// Minimize the Heights II

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int maxHeight = arr[n-1];
        int minHeight = arr[0];
        int minDiff = maxHeight - minHeight;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-k < 0)
            {
                continue;
            }
            int maxx = max(arr[i-1]+k, arr[n-1]-k);
            int minn = min(arr[0]+k, arr[i]-k);
            minDiff = min(minDiff, maxx-minn);
        }
        
        return minDiff;
    }
};