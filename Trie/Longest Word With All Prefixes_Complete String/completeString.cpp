// Longest Word With All Prefixes  Complete String

#include <bits/stdc++.h> 

class TrieNode
{
    public:
        TrieNode* children[26];
        bool flag = false;

        bool containsKey(char ch)
        {
            return (children[ch - 'a'] != NULL);
        }

        TrieNode* getKey(char ch)
        {
            return children[ch - 'a'];
        }

        void putKey(char ch, TrieNode* node)
        {
            children[ch - 'a'] = node;
        }

        void setFlag()
        {
            flag = true;
        }

        bool isEnd()
        {
            return flag;
        }
};

class Trie
{
    public:
        TrieNode* root;
        Trie()
        {
            root = new TrieNode();
        }

        void insertWord(string s)
        {
            TrieNode* temp = root;
            for(int i=0;i<s.length();i++)
            {
                if(!temp->containsKey(s[i]))
                {
                    temp->putKey(s[i], new TrieNode());
                }
                temp = temp->getKey(s[i]);
            }
            temp->setFlag();
        }

        bool isPrefixPossible(string s)
        {
            TrieNode* temp = root;
            for(int i=0;i<s.length();i++)
            {
                if(temp->containsKey(s[i]))
                {
                    temp = temp->getKey(s[i]);
                    if(!temp->isEnd())
                        return false;
                }
            }
            return true;
        }
};


string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto s: a)
    {
        trie.insertWord(s);
    }

    string longestString = "";
    for(auto s: a)
    {
        if(trie.isPrefixPossible(s))
        {
            if(s.length() > longestString.length())
            {
                longestString = s;
            }
            else if(s.length() == longestString.length() && s < longestString)
            {
                longestString = s;
            }
        }
    }

    if(longestString == "")
    {
        return "None";
    }
    
    return longestString;
}