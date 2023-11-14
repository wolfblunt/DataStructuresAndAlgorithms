// Count Number of Homogenous Substrings

class Solution {
public:
    int countHomogenous(string s) {
        int count = 0;
        int n = s.length();
        int mod = 1e9+7;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=0 && s[i-1] == s[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            ans = (ans + count)%mod;
        }
        return ans;
    }
};