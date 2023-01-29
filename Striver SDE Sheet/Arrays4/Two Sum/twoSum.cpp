// Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(um.find(target-nums[i]) == um.end())
            {
                um[nums[i]] = i;;
            }
            else
            {
                int start = um[target-nums[i]];
                ans.push_back(start);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};