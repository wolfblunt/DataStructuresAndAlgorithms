// Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um = {{ 'I', 1},
                                        { 'V', 5},
                                        { 'X', 10},
                                        { 'L', 50},
                                        { 'C', 100},
                                        { 'D', 500},
                                        { 'M', 1000}};
        
        int n = s.length();
        int sum = um[s[n-1]];

        for(int i=n-2;i>=0;i--)
        {
            if(um[s[i]] < um[s[i+1]])
            {
                sum -= um[s[i]];
            }
            else
            {
                sum += um[s[i]];
            }
        }

        return sum;
    }
};