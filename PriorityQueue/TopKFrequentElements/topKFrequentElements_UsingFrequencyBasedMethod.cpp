// Using frequency-based array method

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // O(n)
        for(auto a: nums)
        {
            mp[a]++;
        }

        /** as the word frequencies is at most nums.size() **/
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> result;

        for(auto i: mp)
        {
            buckets[i.second].push_back(i.first);
        }

        /** we can fetch the top k largest element value from the array **/    
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