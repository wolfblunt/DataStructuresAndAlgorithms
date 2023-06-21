// Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        string result="";
        for(int i=0;i<s[0].length();i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i == s[j].length() || s[j][i] != s[0][i])
                {
                    return result;
                }
            }
            result+=s[0][i];
        }

        return result;
    }
};