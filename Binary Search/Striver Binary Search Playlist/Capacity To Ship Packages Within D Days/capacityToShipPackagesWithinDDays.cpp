// Capacity To Ship Packages Within D Days

class Solution {
public:
    bool isPossible(vector<int>& A, int barrier, int partition)
    {
        int n = A.size();
        int allotedStudent = 0;
        int pages = 0;
        
        for(int i=0;i<n;i++)
        {
            if(pages + A[i] > barrier)
            {
                allotedStudent += 1;
                pages = A[i];
                if (pages > barrier) 
                {
                    return false;
                }
            }
            else
            {
                pages += A[i];
            }
        }
        
        if(allotedStudent < partition)
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