// Capacity To Ship Packages Within D Days

class Solution {
public:
    bool isPossible(vector<int>& A, int barrier, int days)
    {
        int n = A.size();
        int totalDays = 0;
        int dayCapacity = 0;
        
        for(int i=0;i<n;i++)
        {
            if(dayCapacity + A[i] > barrier)
            {
                totalDays += 1;
                dayCapacity = A[i];
                if (dayCapacity > barrier) 
                {
                    return false;
                }
            }
            else
            {
                dayCapacity += A[i];
            }
        }
        
        if(totalDays < days)
        {
            return true;
        }
        return false;
    }
        

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = weights[0];
        int high = 0;
        for(int i=0;i<n;i++)
        {
            high += weights[i];
            low = min(low, weights[i]);
        }

        while(low<=high)
        {
            int mid = (low + high) >> 1;
            if(isPossible(weights, mid, days))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};