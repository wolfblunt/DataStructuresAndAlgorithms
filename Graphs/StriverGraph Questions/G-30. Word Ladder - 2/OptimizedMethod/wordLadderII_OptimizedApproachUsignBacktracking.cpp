// Word Ladder II - Optimized Approach Using BackTracking

class Solution {
public:
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string> &seq)
    {
        if(word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        for(int i=0;i<sz;i++)
        {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push({beginWord});

        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        mpp[beginWord] = 1;
        int size = beginWord.size();
        b = beginWord;
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int level = mpp[word];

            if(word == endWord)
            {
                break;
            }

            for(int i=0;i<size;i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(s.find(word) != s.end())
                    {
                        q.push(word);
                        s.erase(word);
                        mpp[word] = level+1;
                    }
                }
                word[i] = original;
            }
        }

        if(mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};