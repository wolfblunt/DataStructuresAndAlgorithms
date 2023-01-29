// Lexicographically Smallest Equivalent String  - Using Union and Find

class Solution {
public:
    int find(int a, vector<int> &ch)
    {
        if(ch[a]==-1)
        {
            return a;
        }
        return ch[a] = find(ch[a], ch);
    }

    void union1(int a, int b, vector<int> &ch)
    {
        a = find(a, ch);
        b = find(b, ch);
        if(a!=b)
        {
            ch[max(a,b)] = min(a,b);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<int> ch(26,-1);
        for(auto i=0;i<n;i++)
        {
            union1(s1[i]-'a', s2[i]-'a', ch);
        }
        int m = baseStr.length();
        for(auto i=0;i<m;i++)
        {
            baseStr[i] = find(baseStr[i] - 'a', ch) + 'a';
        }
        return baseStr;
    }
};