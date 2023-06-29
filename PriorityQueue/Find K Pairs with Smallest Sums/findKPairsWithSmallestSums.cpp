// Find K Pairs with Smallest Sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto a: nums1)
        {
            pq.push({a + nums2[0], 0});
        }

        vector<vector<int>> result;
        while(k-- && !pq.empty())
        {
            int sum = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            result.push_back({sum-nums2[pos], nums2[pos]});

            if(pos+1 < nums2.size())
            {
                pq.push({sum - nums2[pos] + nums2[pos+1], pos+1});
            }
        }

        return result;
    }
};