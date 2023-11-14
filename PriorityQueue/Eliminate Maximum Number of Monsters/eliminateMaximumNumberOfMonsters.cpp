// Eliminate Maximum Number of Monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = dist.size();
        for(int i=0;i<n;i++)
        {
            pq.push(ceil((double)dist[i]/speed[i]));
        }

        int ans = 0;
        int currentTime = 0;
        while(!pq.empty())
        {
            if(currentTime < pq.top())
            {
                ans++;
                pq.pop();
            }
            else
            {
                return ans;
            }
            currentTime++;
        }

        return ans;
    }
};