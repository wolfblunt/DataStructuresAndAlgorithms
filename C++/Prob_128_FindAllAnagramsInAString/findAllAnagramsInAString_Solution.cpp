// Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string str, string ptr) {
        int n = str.length();
        int m = ptr.length();
        if(n<m)
        {
          return {};
        }
        vector<int> ptrFreq(26,0);
        vector<int> strFreq(26,0);

        for(int i=0;i<m;i++)
        {
            ptrFreq[ptr[i]-'a']++;
        }

        int i=0, j=0;
        while(m--)
        {
            strFreq[str[j] - 'a']++;
            j++;
        }

        vector<int> ans;

        if(ptrFreq == strFreq)
        {
            ans.push_back(i);
        }

        while(j<n)
        {
            strFreq[str[i++] - 'a']--;
            strFreq[str[j++] - 'a']++;
            if(ptrFreq == strFreq)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};