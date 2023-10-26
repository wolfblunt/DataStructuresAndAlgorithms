// Number of Good Ways to Split a String

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char> preSet, postSet;
        vector<int> prefixArray(n,0);
        vector<int> suffixArray(n,0);
        
        for(int i=0;i<n;i++)
        {
            preSet.insert(s[i]);
            prefixArray[i] = preSet.size();
            postSet.insert(s[n-1-i]);
            suffixArray[n-1-i] = postSet.size();
        }

        int ans = 0;
        for(int i=0;i<n-1;i++)
        {
            if(prefixArray[i] == suffixArray[i+1])
            {
                ans++;
            }
        }

        return ans;
    }
};