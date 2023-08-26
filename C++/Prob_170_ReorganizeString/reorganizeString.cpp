// Reorganize String

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq_map;
        for(int i=0;i<s.length();i++)
        {
            freq_map[s[i]]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto a: freq_map)
        {
            maxHeap.push({a.second, a.first});
        }

        string ans = "";
        while(maxHeap.size() >= 2)
        {
            auto ele1 = maxHeap.top();
            maxHeap.pop();
            char char1 = ele1.second;
            int freq1 = ele1.first;
            auto ele2 = maxHeap.top();
            maxHeap.pop();
            char char2 = ele2.second;
            int freq2 = ele2.first;
            ans += char1;
            ans += char2;

            if(--freq1)
            {
                maxHeap.push({freq1, char1});
            }
            if(--freq2)
            {
                maxHeap.push({freq2, char2});
            }
        }

        if(!maxHeap.empty())
        {
            int freq = maxHeap.top().first;
            char ch = maxHeap.top().second;
            if(freq > 1)
            {
                return "";
            }
            ans += ch;
        }

        return ans;
    }
};