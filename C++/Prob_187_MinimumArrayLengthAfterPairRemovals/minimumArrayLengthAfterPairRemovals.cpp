// Minimum Array Length After Pair Removals

// Edge test Cases
// [2,3,3,3,4]  => Output: 1
// [2,3,4,4,4] => Output: 1
// [1]  => Output: 1

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums)
    {
        unordered_map<int, int> um; 
        int n = nums.size(); 
         
        for (int i = 0; i < n; i++)
        { 
            um[nums[i]]++; 
        } 
         
        int maxi = 0; 
        for (auto a : um)
        { 
            maxi = max(maxi, a.second); 
        } 
         
        if (maxi > n / 2) 
        { 
            return 2 * maxi - n; 
        } 
         
        if (n % 2 == 0) 
        { 
            return 0; 
        }
        
        return 1; 
    }
};