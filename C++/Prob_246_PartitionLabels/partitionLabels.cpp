// Partition Labels - O(n)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, 0);
        vector<int> ans;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            lastOccurrence[s[i]-'a'] = i;
        }

        int startString = 0, endString = 0;
        for(int i=0;i<n;i++)
        {
            endString = max(lastOccurrence[s[i]-'a'], endString);
            if(endString == i)
            {
                ans.push_back(endString-startString+1);
                startString = i+1;
            }
        }

        return ans;
    }
};