// Non-overlapping Intervals

/*
	APPROACH
	1. Sort the Array in Non Decreasing order
	2. Choose r as the closing of First Interval
	3. if(r>opening interval), there is an overlap, and we will increase our count, and take minimum of both
	4. else we will update r
	5. return cnt
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int end = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(end > intervals[i][0])
            {
                count++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return count;
    }
};