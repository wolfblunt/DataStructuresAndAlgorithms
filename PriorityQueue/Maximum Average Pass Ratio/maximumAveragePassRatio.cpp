// Maximum Average Pass Ratio: O(NLogN)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    long double calculateGain(int pass, int totalStud)
    {
        return (long double)(pass+1) / (long double)(totalStud+1) - (long double)(pass) / (long double)(totalStud);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<long double, pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            int pass = classes[i][0];
            int totalStud = classes[i][1];
            long double gain = calculateGain(pass, totalStud);
            pq.push({gain, {pass, totalStud}});
        }

        for(int i=1;i<=extraStudents;i++)
        {
            auto [currenGain, classInfo] = pq.top();
            pq.pop();
            int pass = classInfo.first;
            int totalStud = classInfo.second;
            long double newGain = calculateGain(pass+1, totalStud+1);
            pq.push({newGain, {pass+1, totalStud+1}});
        }

        long double ans = 0;
        while(!pq.empty())
        {
            auto [currenGain, classInfo] = pq.top();
            pq.pop();
            ans += (long double)(classInfo.first) / (long double)(classInfo.second);
        }

        ans = ans / n;
        return ans;
    }
};