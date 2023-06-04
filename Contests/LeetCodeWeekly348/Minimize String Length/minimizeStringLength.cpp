// Minimize String Length
 
class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char, int> um;
        for(int i=0;i<s.length();i++)
        {
            um[s[i]] = 1;
        }
        
        string ss="";
        for(auto a: um)
        {
            if(a.second == 1)
            {
                ss += a.first;
            }
        }
        return ss.size();
    }
};