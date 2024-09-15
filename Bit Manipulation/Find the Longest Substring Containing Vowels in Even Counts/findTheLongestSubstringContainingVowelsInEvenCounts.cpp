// Find the Longest Substring Containing Vowels in Even Counts - O(n)

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> um;
        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int mask = 1;
        for(auto &a: vowel)
        {
            um[a] = mask;
            mask = mask*2;
        }
        // vowel['a'] = 1, vowel['e'] = 2, vowel['i'] = 4, vowel['o'] = 8, vowel['u'] = 16 

        mask = 0;
        int ans = 0;
        vector<int> seen(32, -1);
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(um.find(s[i]) != um.end())
            {
                mask = mask ^ (um[s[i]]); // for vowels
            }
            else
            {
                mask = mask ^ 0; // for consonants
            }

            if(mask!=0 && seen[mask] == -1)
            {
                seen[mask] = i;
            }

            ans = max(ans, i - seen[mask]);
        }

        return ans;
    }
};