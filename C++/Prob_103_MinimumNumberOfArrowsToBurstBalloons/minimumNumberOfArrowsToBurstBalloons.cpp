// Minimum Number of Arrows to Burst Balloons
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lastpoint = points[0][1];
        int count=1;
        for(auto a: points)
        {
            if(lastpoint<a[0])
            {
                ++count;
                lastpoint = a[1];
            }
            else
            {
                lastpoint = min(lastpoint, a[1]);
            }
        }
        return count;
    }
};