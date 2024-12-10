// Kth Missing Positive Number - O(logn)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int missing = arr[mid]-(mid+1);
            if(missing < k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return k+high+1; // or k+low
    }
};