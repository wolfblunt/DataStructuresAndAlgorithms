// Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m)
        {
            return false;
        }
        unordered_map<char, int> um;
        for(int i=0;i<n;i++)
        {
            um[s[i]]++;
        }

        for(int i=0;i<m;i++)
        {
            if(um.find(t[i]) == um.end())
            {
                return false;
            }
            else
            {
                um[t[i]]--;
            }
        }
        for(auto a: um)
        {
            if(a.second)
                return false;
        }
        return true;
    }
};