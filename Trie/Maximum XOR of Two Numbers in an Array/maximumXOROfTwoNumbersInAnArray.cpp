// Maximum XOR of Two Numbers in an Array

class TrieNode
{
    public:
    TrieNode* children[2];

    bool containsBit(int n)
    {
        return children[n] != NULL;
    }

    TrieNode* getBit(int n)
    {
        return children[n];
    }

    void putBit(int n, TrieNode* node)
    {
        children[n] = node;
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
    void insert(int num)
    {
        TrieNode* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(!node->containsBit(bit))
            {
                node->putBit(bit, new TrieNode());
            } 
            node = node->getBit(bit);
        }
    }

    int getMax(int num)
    {
        TrieNode* node = root;
        int maximum = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(node->containsBit(1-bit))
            {
                node = node->getBit(1-bit);
                maximum = maximum | (1<<i);
            }
            else
            {
                node = node->getBit(bit);
            }
        }
        return maximum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int maxi=0;
        Trie node;
        for(auto a: nums)
        {
            node.insert(a);
        }

        for(auto a: nums)
        {
            maxi = max(maxi, node.getMax(a));
        }
        return maxi;
    }
};