// Maximum XOR With an Element From Array

class TrieNode
{
    public:
    TrieNode* children[2];
    
    bool containsBit(int bit)
    {
        return (children[bit] != NULL);
    }

    TrieNode* getBit(int bit)
    {
        return children[bit];
    }

    void putBit(int bit, TrieNode* node)
    {
        children[bit] = node;
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
            int bit = (num >> i) & 1;
            if(!node->containsBit(bit))
            {
                node->putBit(bit, new TrieNode());
            }

            node = node->getBit(bit);
        }
    }

    int maxXor(int num)
    {
        TrieNode* node = root;
        int maximum = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(node->containsBit(!bit))
            {
                node = node->getBit(!bit);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, pair<int, int>>> oQ;
        sort(nums.begin(), nums.end());
        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oQ.begin(), oQ.end());
        int index = 0;
        int n = nums.size();
        int nn = oQ.size();
        vector<int> ans(q,0);
        Trie trie;
        for(int i=0;i<nn;i++)
        {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while(index<n && nums[index] <= ai)
            {
                trie.insert(nums[index]);
                index++;
            }
            if(index==0)
            {
                ans[qInd] = -1;
            }
            else
            {
                ans[qInd] = trie.maxXor(xi);
            }
        }
        return ans;
    }
};