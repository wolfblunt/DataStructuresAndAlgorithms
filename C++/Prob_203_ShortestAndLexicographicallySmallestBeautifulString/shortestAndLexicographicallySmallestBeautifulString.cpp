// Shortest and Lexicographically Smallest Beautiful String

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<int> prefixSum(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1] = prefixSum[i] + (s[i]-'0');
        }
        
        int maxLen = INT_MAX;
        string ans = "";
        for(int right=0;right<n;right++)
        {
            for(int left=0;left<=right;left++)
            {
                int noOfOnes = prefixSum[right+1] - prefixSum[left];
                if(noOfOnes == k)
                {
                    int len = right-left;
                    if(len < maxLen)
                    {
                        maxLen = len;
                        ans = s.substr(left, len+1);
                    }
                    else if(len == maxLen)
                    {
                        ans = min(ans, s.substr(left, len+1));
                    }
                }
            }
        }
        
        return ans;
    }
};