// Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um; // max heap
        for(auto a: nums)
        {
            um[a]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto a: um)
        {
            pq.push({a.second, a.first});
        }

        vector<int> ans;
        while(k-- && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};