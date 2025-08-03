// Maximize partitions in a String - O(n)

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.length();
        unordered_map<char, int> um;
        for(int i=0;i<n;i++)
        {
            um[s[i]] = i;
        }
        
        int ans = 0;
        int maxCount = 0;
        for(int i=0;i<n;i++)
        {
            maxCount = max(maxCount, um[s[i]]);
            if(maxCount == i)
            {
                ans++;
            }
        }
        
        return ans;
    }
};