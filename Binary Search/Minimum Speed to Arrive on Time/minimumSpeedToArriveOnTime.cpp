// Minimum Speed to Arrive on Time

class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed)
    {
        double time=0;
        int n= dist.size();
        for(int i=0;i<n;i++)
        {
            double t = dist[i]*(1.0)/speed;
            if(i != n-1)
            {
                time = time + ceil(t); // take the integer value because train is running on integer hour
            }
            else
            {
                // at last station we don't have to convert it into next integer because this is the last train 
                // or at last station we don't have to wait for additional time
                time += t; 
            }            
        }
        return (time<=hour);
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = (int)(1e7+5);
        while(low<high)
        {
            int mid = low + (high-low) / 2;
            if(isPossible(dist, hour, mid))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return (low < 1e7+1 ? low:-1);
    }
};