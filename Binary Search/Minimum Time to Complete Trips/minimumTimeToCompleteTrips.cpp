// Minimum Time to Complete Trips

#include<bits/stdc++.h>
class Solution {
public:
    long long totalTripInGivenTime(long long givenTime, vector<int>& time)
    {
        long long totalTrips = 0;
        for(auto a: time)
        {
            long long val = a;
            totalTrips+= (long long)(givenTime/ val);
        }
        return totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long minTime = time[0];
        for(auto a: time)
        {
            long long aa = a;
            minTime = min(minTime, aa);
        }
        long long right = minTime*totalTrips;

        while(left<right)
        {
            long mid = (right-left)/2 + left;
            if(totalTripInGivenTime(mid, time) < totalTrips)
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};