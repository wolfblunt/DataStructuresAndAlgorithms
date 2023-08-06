// Letter Combinations of a Phone Number

class Solution {
public:
    void backtrack(string &digits, unordered_map<char, string> &digitToLetter, string temp, int index, vector<string> &ans)
    {
        if(temp.size() == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string s = digitToLetter[digits[index]];
        for(auto a: s)
        {
            temp.push_back(a);
            backtrack(digits, digitToLetter, temp, index+1, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digitToLetter = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans; 
        if(digits.size() == 0)
        {
            return ans;
        }

        backtrack(digits, digitToLetter, "", 0, ans);
        return ans;
    }
};