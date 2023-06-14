// Neither Minimum nor Maximum


class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int a = *max_element(nums.begin(), nums.end());
        int b = *min_element(nums.begin(), nums.end());
        int ans = -1;
        for(auto c: nums)
        {
            if(c != a && c!=b)
            {
                ans = c;
                break;
            }
        }
        return ans;
    }
};