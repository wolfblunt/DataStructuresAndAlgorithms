//  Minimum Absolute Difference Between Elements With Constraint

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> s;
        int ans = 1e9;
        for(int i=x;i<n;i++)
        {
            s.insert(nums[i-x]);
            auto index = s.lower_bound(nums[i]);
            if(index!=s.end())
            {
                /* The function returns an iterator pointing to the element in the container which is
                equivalent to k passed in the parameter. In case k is not present in the set container,
                the function returns an iterator pointing to the immediate next element which is just 
                greater than k. If the key passed in the parameter exceeds the maximum value in the
                container, then the iterator returned is equivalent to s.end() */
                ans = min(ans, abs(*index - nums[i]));
            }
            if(index != s.begin())
            {
                index--;
                ans = min(ans, abs(*index - nums[i]));
            }
        }   
        return ans;  
    }
};