// Longest String Chain

class Solution {
public:
    bool checkIfPossible(string& s1, string& s2)
    {
        if(s1.size() != s2.size() + 1)
        {
            return false;
        }

        int first = 0;
        int second = 0;
        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if(first == s1.size() && second == s2.size())
        {
            return true;
        }
        return false;
    }

    static bool comp(string& s1, string& s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        sort(words.begin(), words.end(), comp);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkIfPossible(words[i], words[prev]) && dp[i] < dp[prev] + 1)
                {
                    dp[i] = dp[prev] + 1;
                }
            }

            if(maxi < dp[i])
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};