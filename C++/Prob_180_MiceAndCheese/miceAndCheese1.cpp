// Mice and Cheese

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int, int>> pq;
        int n = reward1.size();
        for(int i=0;i<n;i++)
        {
            pq.push({reward1[i] - reward2[i], i});
        }

        unordered_set<int> us;
        int maxPoint = 0;
        while(k && !pq.empty())
        {
            int index = pq.top().second;
            us.insert(index);
            maxPoint += reward1[index];
            k--;
            pq.pop();
        }

        for(int i=0;i<n;i++)
        {
            if(us.find(i) == us.end())
            {
                maxPoint += reward2[i];
            }
        }

        return maxPoint;
    }
};