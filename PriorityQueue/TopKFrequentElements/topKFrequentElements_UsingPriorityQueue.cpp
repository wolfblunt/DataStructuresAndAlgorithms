// Using Priority Queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // O(n)
        for(auto a: nums)
        {
            mp[a]++;
        }

        priority_queue<pair<int, int>> pq; // O(nlogn)
        vector<int> result;

        for(auto it: mp)
        {
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > mp.size()-k)
            {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};