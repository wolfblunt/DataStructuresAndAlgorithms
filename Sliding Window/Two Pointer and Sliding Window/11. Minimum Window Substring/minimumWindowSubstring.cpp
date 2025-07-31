// Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> freq;
        int left = 0;
        int right = 0;
        for(auto a: t)
        {
            freq[a]++;
        }

        int count = 0;
        int minLen = 1e9;
        int sIndex = -1;
        while(right < n)
        {
            if(freq[s[right]] > 0)
            {
                count++;
            }

            freq[s[right]]--;
            while(count == m)
            {
                if(right-left+1 < minLen)
                {
                    minLen = right-left+1;
                    sIndex = left;
                }

                freq[s[left]]++;
                if(left <= right && freq[s[left]] > 0)
                {
                    count = count-1;
                }
                left++;
            }
            right++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};