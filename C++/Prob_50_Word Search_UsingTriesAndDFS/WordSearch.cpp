class TrieNode{
    public:
    string word;
    TrieNode* child[26];
    bool isWord;
    
    TrieNode()
    {
        isWord = false;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root;
     vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    
    void insert(TrieNode* root, string word)
    {
        TrieNode* curr = root;
        
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            
            curr = curr->child[index];
        }
        curr->word = word;
        curr->isWord = true;
    }
    // board, ans, i, j, root
    void DFS(vector<vector<char>>& board, vector<string> &ans, int i, int j,TrieNode* root)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='*' || !(root->child[board[i][j]-'a']))
            return;
        
        root = root->child[board[i][j] - 'a'];
        
        if(root->isWord)
        {
            ans.push_back(root->word);
            root->isWord = false;
        }
        
        char c=board[i][j];
        board[i][j] = '*';
        
        for(int k=0;k<4;k++)
        {
            int ni = i+dx[k];
            int nj = j+dy[k];
            
            DFS(board, ans, ni, nj, root);
        }
        board[i][j] = c;
        return;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto word: words)
            insert(root, word);
        
        TrieNode* temp = root;
        vector<string> ans;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                DFS(board, ans, i, j, temp);
            }
        }
        
        return ans;
    }
};