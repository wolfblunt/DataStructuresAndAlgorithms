class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<int, int> mp;
        for(int i=0;i<magazine.length();i++)
        {
            mp[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();i++)
        {
            if(mp[ransomNote[i]]>=1)
            {
                mp[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};