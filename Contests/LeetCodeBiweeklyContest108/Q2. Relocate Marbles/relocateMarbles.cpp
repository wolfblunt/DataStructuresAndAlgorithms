// Relocate Marbles

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = moveFrom.size();
        int m = nums.size();
        map<int, long long> freq;
        for(int i=0;i<m;i++)
        {
            freq[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            freq[moveTo[i]] += freq[moveFrom[i]];
            if(moveTo[i] != moveFrom[i])
            {
                freq[moveFrom[i]] = 0;
            }
        }
        
        vector<int> ans;
        for(auto a: freq)
        {
            if(a.second > 0)
                ans.push_back(a.first);
        }
        return ans;
    }
};