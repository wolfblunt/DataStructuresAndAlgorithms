// Sort Colors

class Solution {
public:
    void sortColors(vector<int>& a) {
        int low = 0;
        int mid = 0;
        int high = a.size()-1;
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                int t = a[mid];
                a[mid] = a[low];
                a[low] = t;
                low++;
                mid++;
            }
            else if(a[mid]==1)
            {
                mid++;
            }
            else
            {
                int t = a[high];
                a[high] = a[mid];
                a[mid] = t;
                high--;
            }
        }
    }
};