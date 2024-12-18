// Minimize Max Distance to Gas Station: O(n*log k)

class Solution {
  public:
    int helper(vector<int> &stations, long double mid)
    {
        int count = 0;
        int n = stations.size();
        for(int i=1;i<n;i++)
        {
            int numberOfStationInBetween = (stations[i] - stations[i-1]) / mid;
            if((numberOfStationInBetween * mid) == ((stations[i] - stations[i-1]) / mid))
            {
                numberOfStationInBetween--;   
            }
            count += numberOfStationInBetween;
        }
        
        return count;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        long double low = 0;
        long double high = 0;
        int n = stations.size();
        for(int i=1;i<n;i++)
        {
            high = max(high, ((long double)(stations[i] - stations[i-1])));
        }
        
        long double diff = 1e-6;
        while(high - low > diff)
        {
            long double mid = (low + high)/(2.0);
            int count = helper(stations, mid);
            
            if(count > k)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        
        return high;
    }
};