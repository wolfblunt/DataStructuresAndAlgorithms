// Longest Substring Without Repeating Characters - O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 1)
        {
            return 1;
        }
        int l = 0;
        int r = 0;
        int maxlen = 0;
       unordered_map<int, int> um;
        for(;r<n;r++)
        {
            if(um.count(s[r]-'a'))
            {
                l = max(l, um[s[r] - 'a']+1) ;
            }
            um[s[r]-'a'] = r;
            maxlen = max(maxlen, r-l+1);
        }

        return maxlen;
    }
};