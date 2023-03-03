// Find the Index of the First Occurrence in a String

class Solution {
public:
    void LongestPrefixSumArray(string needle, int m, int* lps)
    {
        int len=0;
        lps[len]=0;
        int i=1;
        while(i<m)
        {
            if(needle[i]==needle[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        int lps[m];
        LongestPrefixSumArray(needle, m, lps);
        int i=0;
        int j=0;
        while((n-i) >= (m-j))
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return i-j;
            }
            else if(i<n && haystack[i]!=needle[j])
            {
                if(j!=0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};