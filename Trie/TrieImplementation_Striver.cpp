class TrieNode {
public:
    TrieNode* children[26];
    bool flag;

    bool containsKey(char ch)
    {
        return (children[ch-'a'] != NULL);
    }

    TrieNode* get(char ch)
    {
        return children[ch-'a'];
    }

    void put(char ch, TrieNode* node)
    {
        children[ch-'a'] = node;
    }

    bool setEnd()
    {
        flag = true;
        return flag;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if(node->isEnd())
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    // Search for words
    cout << "Search for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    
    // Check prefixes
    cout << "Starts with 'ap': " << (trie.startsWith("ap") ? "Yes" : "No") << endl;
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */