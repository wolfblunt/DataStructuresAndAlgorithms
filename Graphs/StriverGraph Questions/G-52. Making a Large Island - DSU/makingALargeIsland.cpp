// Making A Large Island

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    
    int findUltimateParent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionOpUsingSize(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv)
        {
            return;
        }
        
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;
        parent.resize(n*m);
        size.resize(n*m, 1);
        
        for(int i=0;i<n*m;i++)
        {
            parent[i] = i;
        }
        
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // Step1- Making Union of Adjacent Components
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }
                
                for(auto a: dir)
                {
                    int adjr = a[0]+i;
                    int adjc = a[1]+j;
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && grid[adjr][adjc]==1)
                    {
                        int nodeNo = i*m + j;
                        int adjNodeNo = adjr*m + adjc;
                        unionOpUsingSize(nodeNo, adjNodeNo);
                    }
                }
                
            }
        }
        
        int maxConn = 0;
        
        // Step2 - try converting all 0's to 1
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<m; col++)
            {
                if(grid[row][col] == 1)
                {
                    continue;
                }
                
                set<int> components;
                for(auto a: dir)
                {
                    int adjr = a[0]+row;
                    int adjc = a[1]+col;
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<m)
                    {
                        if(grid[adjr][adjc]==1)
                        {
                            int nodeNo = row*m + col;
                            int adjNodeNo = adjr*m + adjc;
                            components.insert(findUltimateParent(adjNodeNo));
                        }
                    }
                }
                
                int totalsize = 0;
                for(auto a: components)
                {
                    totalsize += size[a]; 
                }
                maxConn = max(totalsize+1, maxConn);
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            maxConn = max(maxConn, size[findUltimateParent(i)]);
        }
        
        return maxConn;
    }
};