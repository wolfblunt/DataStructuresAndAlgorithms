// Longest Palindromic Substring


class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 1;
        int l,h;
        int n = s.length();
        int maxlen = 1;
        for(int i=1;i<n;i++)
        {
            // odd
            l = i-1;
            h = i+1;

            while(l>=0 && h<n && s[l] == s[h])
            {
                if(h-l+1 > maxlen)
                {
                    maxlen = h-l+1;
                    start = l;
                    end = h-l+1;
                }
                l--;
                h++;
            }

            // even
            l = i;
            h = i-1;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > maxlen)
                {
                    maxlen = h-l+1;
                    start = l;
                    end = h-l+1;
                }
                l--;
                h++;
            }
        }

        string result = s.substr(start, end);
        return result;
    }
};