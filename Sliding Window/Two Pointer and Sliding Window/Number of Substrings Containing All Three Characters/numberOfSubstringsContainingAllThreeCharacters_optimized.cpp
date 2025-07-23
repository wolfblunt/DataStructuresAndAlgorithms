// Number of Substrings Containing All Three Characters - O(N)

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v = {-1,-1,-1};
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            v[s[i] - 'a'] = i;
            if(v[0] != -1 && v[1] != -1 && v[2] != -1)
            {
                ans += min({v[0], v[1], v[2]}) + 1;
            }
        }

        return ans;
    }
};