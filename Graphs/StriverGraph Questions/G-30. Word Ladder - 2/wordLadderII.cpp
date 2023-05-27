// Word Ladder II

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> s(wordList.begin(), wordList.end());
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> result;

        while(!q.empty())
        {
            vector<string> v = q.front();
            q.pop();

            if(v.size() > level)
            {
                level++;
                for(auto a: usedOnLevel)
                {
                    s.erase(a);
                }
            }

            string word = v.back();

            if(word == endWord)
            {
                if(result.size()==0)
                {
                    result.push_back(v);
                }
                else if(result[0].size() == v.size())
                {
                    result.push_back(v);
                }
            }

            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    word[i] = ch;
                    if(s.find(word) != s.end())
                    {
                        v.push_back(word);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        q.push(v);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return result;
    }
};


bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}