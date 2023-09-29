// Decoded String at Index

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long s_length = 0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                s_length++;
            }
            else
            {
                s_length = s_length*(s[i]-'0');
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            k = k % s_length;
            if(k==0 && isalpha(s[i]))
            {
                return string(1, s[i]);
            }

            if(isalpha(s[i]))
            {
                s_length--;
            }
            else
            {
                s_length = s_length/(s[i]-'0');
            }
        }

        return "";
    }
};