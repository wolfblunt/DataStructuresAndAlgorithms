// Find Right Interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);

        vector<pair<int, int>> startIndices;

        for(int i=0;i<n;i++)
        {
            startIndices.push_back({intervals[i][0], i});
        }

        sort(startIndices.begin(), startIndices.end());

        for(int i=0;i<n;i++)
        {
            int low = 0;
            int high = n-1;
            int currentEnd = intervals[i][1];
            int rightIntervalIndex = -1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(startIndices[mid].first >= currentEnd)
                {
                    rightIntervalIndex = startIndices[mid].second;
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            ans[i] = rightIntervalIndex;
        }

        return ans;
    }
};