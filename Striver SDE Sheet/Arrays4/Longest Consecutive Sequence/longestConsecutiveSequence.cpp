// Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> us(nums.begin(), nums.end());
        int result = 1;
        for(auto a: nums)
        {
            if(us.find(a) == us.end())
            {
                continue;
            }
            us.erase(a);
            int previous = a-1;
            int next = a+1;
            while(us.find(previous)!=us.end())
            {
                us.erase(previous);
                previous--;
            }
            while(us.find(next)!=us.end())
            {
                us.erase(next);
                next++;
            }
            result = max(result, next-previous-1);
        }
        return result;
    }
};