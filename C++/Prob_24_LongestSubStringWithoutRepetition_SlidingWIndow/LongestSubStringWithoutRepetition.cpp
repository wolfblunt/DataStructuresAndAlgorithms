class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> um;
        int right=0;
        int left=0;
        int maxlen=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(!um.count(s[i]))
            {
                um[s[i]]=i;
            }
            else{
                left=max(um[s[i]]+1,left);
                um[s[i]]=i;
            }
            maxlen=max(maxlen, right-left+1);
            cout<<maxlen<<" ";
            right++;
        }
        return maxlen;
    }
};


// Input : "abba"