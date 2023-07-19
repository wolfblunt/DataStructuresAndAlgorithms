// Lexicographical Numbers - DFS

class Solution {
public:
    vector<int> ans;
    int size;
    void dfs(int currVal)
    {
        ans.push_back(currVal);
        for(int i=0; i<=9; i++)
        {
            int x = currVal*10 + i;
            if(x>size)
                return;
            
            dfs(x);
        }
    }

    vector<int> lexicalOrder(int n) {
        size = n;
        for(int i=1; i<=9 && i<=n; i++)
        {
            dfs(i);
        }
        
        return ans;
    }
};