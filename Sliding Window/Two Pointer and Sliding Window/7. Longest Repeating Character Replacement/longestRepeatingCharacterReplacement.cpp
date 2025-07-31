// Longest Repeating Character Replacement - O(N)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxfreq = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);
        int left = 0;
        for(int right=0;right<n;right++)
        {
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq, freq[s[right]-'A']);

            if(right-left+1 - maxfreq > k)
            {
                freq[s[left]-'A']--;
                left++;
            }

            if(right-left+1 - maxfreq <= k)
            {
                maxLen = max(maxLen, right-left+1);
            }
        }

        return maxLen;
    }
};