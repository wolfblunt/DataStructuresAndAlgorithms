// Longest Substring with K Uniques - O(N)+O(N)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<char, int> um;
        while(r<n)
        {
            um[s[r]]++;
            if(um.size() == k)
            {
                maxlen = max(maxlen, r-l+1);
            }
            else if(um.size() > k)
            {
                while(l<=r && um.size() > k)
                {
                    um[s[l]]--;
                    if(um[s[l]] == 0)
                    {
                        um.erase(s[l]);
                    }
                    
                    l++;
                }
            }
            r++;
        }
        
        return maxlen==0? -1 : maxlen;
    }
};