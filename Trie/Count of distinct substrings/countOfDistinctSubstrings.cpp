// Count of distinct substrings

class TrieNode
{
    public:
    TrieNode* children[26];
    bool flag=false;

    bool containsChar(char ch)
    {
        return (children[ch-'a'] != NULL);
    }

    TrieNode* getChar(char ch)
    {
        return children[ch - 'a'];
    }

    void putChar(char ch, TrieNode* node)
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

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    TrieNode* root = new TrieNode();
    int n = s.length();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        TrieNode* node= root;
        for(int j=i;j<n;j++)
        {
            if(!node->containsChar(s[j]))
            {
                count++;
                node->putChar(s[j], new TrieNode());
            }
            node = node->getChar(s[j]);
        }
        node->setEnd();
    }
    return count+1;
}