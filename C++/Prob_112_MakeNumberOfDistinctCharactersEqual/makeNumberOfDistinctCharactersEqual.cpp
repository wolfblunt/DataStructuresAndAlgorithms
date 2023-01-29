// Make Number of Distinct Characters Equal

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> um1, um2;
        int n = word1.length();
        int m = word2.length();
        for(int i=0;i<n;i++)
        {
            um1[word1[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            um2[word2[i]]++;
        }
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                char ch1 = i+'a';
                char ch2 = j + 'a';
                if(um1.count(ch1) && um2.count(ch2))
                {
                    um1[ch1]--;
                    um2[ch2]--;
                    if(um1[ch1] == 0)
                        um1.erase(ch1);
                    
                    if(um2[ch2] == 0)
                        um2.erase(ch2);
                    
                    um1[ch2]++;
                    um2[ch1]++;
                    if(um1.size() == um2.size())
                    {
                        return true;
                    }
                    um1[ch2]--;
                    um2[ch1]--;
                    
                    if(um1[ch2] == 0)
                        um1.erase(ch2);
                    
                    if(um2[ch1] == 0)
                        um2.erase(ch1);
                    
                    um1[ch1]++;
                    um2[ch2]++;
                }
            }
        }
        return false;
    }
};