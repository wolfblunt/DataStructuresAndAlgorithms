// Number of Substrings Containing All Three Characters - O(N) + O(N)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        unordered_map<char, int> um;
        int ans = 0;
        for(int right=0;right<n;right++)
        {
            um[s[right]]++;

            while(um.size() ==3)
            {
                ans += (n-right);
                um[s[left]]--;
                if(um[s[left]] == 0)
                {
                    um.erase(s[left]);
                }
                left++;
            }
        }

        return ans;
    }
};