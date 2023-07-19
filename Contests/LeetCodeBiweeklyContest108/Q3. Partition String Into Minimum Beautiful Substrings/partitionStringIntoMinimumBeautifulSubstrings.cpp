// Partition String Into Minimum Beautiful Substrings

// O(n * 2^n)
class Solution {
public:
    bool isPower5(int num)
    {
        if(num==1)
        {
            return true;
        }
        while(num)
        {
            if(num==1)
            {
                return true;
            }
            if(num%5 != 0)
            {
                return false;
            }
            num = num/5;
        }
        return 0;
    }

    int helper(string s, int t=0)
    {
        if(s.size() == t)
        {
            return 0;
        }
        int num = 0;
        int r = INT_MAX;
        for(int i=t;i<s.size();i++)
        {
            num = (num<<1) + (s[i] - '0');
            if(!num)
            {
                break;
            }
            else if(isPower5(num))
            {
                int temp = helper(s, i+1);
                if(temp != -1)
                {
                    r = min(r, temp+1);
                }
            }
        }

        return r==INT_MAX?-1:r;
    }

    int minimumBeautifulSubstrings(string s) {
        return helper(s);
    }
};