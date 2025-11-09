// Longest Bounded-Difference Subarray : O(n log n) for map

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        map<int, int> mp;
        int n = arr.size();
        int left=0;
        int start = 0;
        int end = 0;
        int maxLen = 0;
        for(int right=0;right<n;right++)
        {
            mp[arr[right]]++;
            while((mp.rbegin()->first) - (mp.begin()->first) > x)
            {
                mp[arr[left]]--;
                if(mp[arr[left]] == 0)
                {
                    mp.erase(arr[left]);
                }
                left++;
            }
            
            if(right-left+1 > maxLen)
            {
                maxLen = right-left+1;
                end = right;
                start = left;
            }
        }
        
        vector<int> ans(arr.begin()+start, arr.begin()+end+1);
        return ans;
    }
};