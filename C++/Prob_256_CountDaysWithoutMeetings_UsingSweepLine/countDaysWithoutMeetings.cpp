// Count Days Without Meetings - O(nlogn)       --- Using Sweep Line Technique

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> v;
        for(auto a: meetings)
        {
            v.push_back({a[0], 1});
            v.push_back({a[1]+1, 0});
        }

        sort(v.begin(), v.end());

        int freeDays = v[0].first - 1;
        int n = v.size();
        int overlap = 0;
        for(int i=0;i<n-1;i++)
        {
            if(v[i].second == 0)
            {
                overlap--;
            }
            else
            {
                overlap++;
            }

            if(overlap == 0)
            {
                freeDays += (v[i+1].first - v[i].first);
            }
        }

        freeDays += days - v.back().first + 1;

        return freeDays;
    }
};