class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        reverse(s.begin(), s.end());
        int end=0, start=0;
        for(int i=0;i<n;i++)
        {
            while (i < n && s[i] != ' ')
            {
                s[end++] = s[i++];
            }

            if (start < end)
            {
                reverse(s.begin() + start, s.begin() + end); 
                if (end == n)
                {
                    break;
                }
                s[end++] = ' ';
                start = end;
            }
        }
        if (end > 0 && s[end-1] == ' ')
        {
            s.resize(end-1);
        }
        else
        {
            s.resize(end);
        }
        return s;
    }
};