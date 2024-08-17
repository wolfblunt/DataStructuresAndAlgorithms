// Maximum Number of Points with Cost - O(n*m) where n=rows, m=cols

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long n = points.size();
        long long m = points[0].size();
        vector<long long> row(points[0].begin(), points[0].end());

        for(long long i=1;i<n;i++)
        {
            vector<long long> next_row(points[i].begin(), points[i].end());
            vector<long long> left(m, 0);
            vector<long long> right(m, 0);

            left[0] = row[0];
            for(long long j=1;j<m;j++)
            {
                left[j] = max(row[j], left[j-1]-1);
            }

            right[m-1] = row[m-1];
            for(long long j=m-2;j>=0;j--)
            {
                right[j] = max(row[j], right[j+1]-1);
            }

            for(long long j=0;j<m;j++)
            {
                next_row[j] += max(left[j], right[j]);
            } 

            row = next_row;           
        }

        return *max_element(row.begin(), row.end());
    }
};