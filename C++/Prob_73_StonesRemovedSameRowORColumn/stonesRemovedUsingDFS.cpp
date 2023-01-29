class Solution {
public:
    bool isSame(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            return true;
        }
        if(a[1] == b[1])
        {
            return true;
        }
        return false;
    }

    void dfs(int currentIndex, vector<vector<int>>& stones, vector<bool>& visited)
    {
        visited[currentIndex] = true;
        for(int i=0;i<stones.size();i++)
        {
            if(visited[i])
            {
                continue;
            }
            if(isSame(stones[currentIndex], stones[i]))
            {
                dfs(i, stones, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int connected=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }
            dfs(i, stones, visited);
            connected++;
        }
        int diff = n-connected;
        return diff;
    }
};