// Decremental String Concatenation

class Solution {
public:
    int dp[1001][50][50];   // dp[noOfWords][firstChar][lastChar]
    
    int helper(vector<string>& words, int index, char firstChar, char lastChar)
    {
        if(index >= words.size())
        {
            return 0;
        }

        if(dp[index][firstChar - 'a'][lastChar - 'a'] != -1)
        {
            return dp[index][firstChar - 'a'][lastChar - 'a'];
        }

        int res1 , res2, wordSize = words[index].size();

        // word[index] + word[index-1]
        res1 = wordSize + helper(words, index+1, words[index][0], lastChar);
        if(words[index].back() == firstChar)
        {
            res1--;
        }

        // word[index-1] + word[index]
        res2 = wordSize + helper(words, index+1, firstChar, words[index].back());
        if(lastChar == words[index][0])
        {
            res2--;
        }

        return dp[index][firstChar - 'a'][lastChar - 'a'] = min(res1, res2);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
        return words[0].size() + helper(words, 1, words[0][0], words[0].back());
    }
};