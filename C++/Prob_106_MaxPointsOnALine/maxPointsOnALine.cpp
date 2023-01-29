// Max Points on a Line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
        {
            return n;
        }
        
        int maxLines=0;
        for(auto a: points)
        {
            unordered_map<double, int> um;
            double x1 = a[0];
            double y1 = a[1];
            for(auto b: points)
            {
                if(a==b)
                    continue;

                double x2 = b[0];
                double y2 = b[1];
                double slope;
                if(x2-x1 == 0)
                {
                    slope = INT_MAX;
                }
                else
                {
                    slope = (y2-y1)/(x2-x1);
                }
                um[slope]++;
                maxLines = max(maxLines, um[slope]);
            } 
        }
        return maxLines+1;
    }
};