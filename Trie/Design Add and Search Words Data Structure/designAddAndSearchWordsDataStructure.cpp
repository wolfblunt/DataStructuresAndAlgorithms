// Design Add and Search Words Data Structure

class TrieNode{
public:
    TrieNode* children[26];
    bool flag;

    bool containsKey(char ch)
    {
        return (children[ch-'a'] != NULL);
    }

    TrieNode* getKey(char ch)
    {
        return children[ch-'a'];
    }

    void put(char ch, TrieNode* node)
    {
        children[ch-'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

void dfs(int i, TrieNode* node, string word, bool &found)
{
    if(found)
    {
        return;
    }

    if(i >= word.length())
    {
        if(node->isEnd())
            found = true;

        return;
    }

    if(word[i] == '.')
    {
        for(int j=0;j<26;j++)
        {
            char ch = (j+'a');
            if(node->containsKey(ch))
            {
                dfs(i+1, node->getKey(ch), word, found);
            }
        }
    }
    else
    {
        if(node->containsKey(word[i]))
        {
            dfs(i+1, node->getKey(word[i]), word, found);
        }
        return;
    }
}

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++)
        {
            char t = word[i];
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        bool found = false;
        dfs(0, node, word, found);
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */