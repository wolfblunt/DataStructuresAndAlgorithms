// Longest K unique characters substring

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        map<char, int> mp;
        int start = 0;
        int end = 0;
        int maxLength = -1;
        int n = s.length();
        for(end=0;end<n;end++)
        {
            mp[s[end]]++;
            if(mp.size() > k)
            {
                while(start<n)
                {
                    mp[s[start]]--;
                    if(mp[s[start]] == 0)
                    {
                        mp.erase(s[start]);
                        break;
                    }
                    start++;
                }
                start++;
            }
            
            if(mp.size() == k)
            {
                maxLength = max(maxLength, end-start+1);
            }
        }
        
        return maxLength;
    }
};