// Top K Frequent Elements -- Using HashMap and vector
// time : < O(nlogn)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // O(n)
        for(auto a: nums)
        {
            mp[a]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> result;

        for(auto i: mp)
        {
            buckets[i.second].push_back(i.first);
        }

        for(int i = buckets.size()-1; i>=0 && result.size() < k; --i)
        {
            for(int num:buckets[i])
            {
                result.push_back(num);
                if(result.size() > k)
                    break;
            }
        }

        return result;
    }
};