// Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(intervals[0][0]);
        v.push_back(intervals[0][1]);
        ans.push_back(v);
        int n = intervals.size();
        for(int i=1;i<n;i++)
        {
            if(v[1]>=intervals[i][0])
            {
                v[1] = max(v[1], intervals[i][1]);
                ans.pop_back();
                ans.push_back(v);
            }
            else
            {
                v[0] = intervals[i][0];
                v[1] = intervals[i][1];
                ans.push_back(v);
            }
        }
        return ans;
    }
};