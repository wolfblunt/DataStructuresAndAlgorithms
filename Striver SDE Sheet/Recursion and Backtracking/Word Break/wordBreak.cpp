// Word Break

class Solution {
public:
    void solveWord(int index, string s, vector<string>& wordDict, string curr, unordered_set<string> &set, vector<string>& ans)
    {
        if(index == s.length())
        {
            curr.pop_back(); // removing the space which we entered in the last or removing trailing white space
            ans.push_back(curr);
        }

        string str = "";
        int n = s.length();
        for(int i=index; i<n; i++)
        {
            str.push_back(s[i]);  //get every substring and check if it exists in set
            if(set.count(str))
            {
                //we have got a word in dict 
                //explore more and get other substrings
                solveWord(i+1, s, wordDict, curr+str+" ", set, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<string> ans;
        for(auto word: wordDict)
        {
            set.insert(word);
        }
        string curr = "";
        solveWord(0, s, wordDict, curr, set, ans);
        return ans;
    }
};