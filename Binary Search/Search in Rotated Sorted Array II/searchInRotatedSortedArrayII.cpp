// Search in Rotated Sorted Array II - O(n/2)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid] == target)
            {
                return true;
            }
            // with duplicates we can have this contdition, just update left & right
            if(arr[mid] == arr[high] && arr[mid] == arr[low])
            {
                low = low+1;
                high = high-1;
                continue;
            }
            if(arr[low] <= arr[mid])
            {
                if(arr[low] <= target && arr[mid] >= target)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            else
            {
                if(arr[mid] <= target && arr[high] >= target)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }

        return false;
    }
};