// Word Pattern 
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> um;
        stringstream ss(s);
        vector<string> v;
        string s1;
        unordered_map<string,bool> visited;
        while (getline(ss, s1, ' '))
        {
            v.push_back(s1);
        }
        if(v.size()!=pattern.length())
            return false;

        for(int i=0;i<pattern.length();i++)
        {
            char ch = pattern[i];
            if(um[ch]=="" && visited[v[i]]==true)
            {
                return false;
            }
            else if(um[ch]=="")
            {
                um[ch] = v[i];
                visited[v[i]] =true;
            }
            else if(um[ch]!=v[i])
            {
                return false;
            }
        }
        return true;
    }
};