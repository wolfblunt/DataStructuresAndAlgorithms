// Sum of Distances in Tree

class Solution {
public:
    void dfs(vector<vector<int>> &adjacent, vector<int> &counter, vector<int> &result, int node, int parent)
    {
        for(auto a: adjacent[node])
        {
            if(a==parent)
                continue;
            dfs(adjacent, counter, result, a, node);
            counter[node] += counter[a];
            result[node] += result[a] + counter[a];
        }
        counter[node]+=1;
    }

    void dfs2(vector<vector<int>> &adjacent, vector<int> &counter, vector<int> &result, int node, int parent, int n)
    {
        for(auto a: adjacent[node])
        {
            if(a==parent)
                continue;
            
            result[a] = result[node] - counter[a] + n - counter[a];
            dfs2(adjacent, counter, result, a, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjacent(n+1);
        vector<int> counter(n);
        vector<int> result(n);
        for(auto a:edges)
        {
            adjacent[a[0]].push_back(a[1]);
            adjacent[a[1]].push_back(a[0]);
        }
        dfs(adjacent, counter, result, 0, -1);
        dfs2(adjacent, counter, result, 0, -1, n);
        return result;
    }
};