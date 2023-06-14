// Lexicographically Smallest String After Substring Operation

class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int start = 0;
        while(s[start]=='a')
        {
            start++;
        }

        if(start==s.size())
        { // if reaches to last so we have to do exactly 1 operation so just change last one
            s[s.size()-1]='z';              
        }

        for(int i=start;i<n;i++)
        {
            if(s[i] == 'a')
                return s;
            else
                s[i] = s[i] - 1;
        }
        
        return s;
    }
};