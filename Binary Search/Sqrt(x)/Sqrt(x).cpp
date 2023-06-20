// Sqrt(x)

class Solution {
public:
    int mySqrt(int x) 
    {
        int low = 1;
        int high = x;

        while(low<=high)
        {
            int mid = low + ((high - low) >> 1);
            if(mid == x/mid)
            {
                return mid;
            }
            else if(mid < x/mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};