// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int left = 0;
        int right = 0;
        int n = s.length();
        int answer = 0;
        while(right < n)
        {
            if(um.find(s[right]) != um.end())
            {
                left = max(left, um[s[right]]+1);
            }
            um[s[right]] = right;
            answer = max(answer, right-left+1);
            right++;
        }
        return answer;
    }
};