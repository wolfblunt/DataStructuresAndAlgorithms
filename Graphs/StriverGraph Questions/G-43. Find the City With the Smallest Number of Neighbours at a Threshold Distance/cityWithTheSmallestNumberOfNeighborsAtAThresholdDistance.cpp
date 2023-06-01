// City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n,1e7));
        int m = edges.size();
        for(int k=0;k<m;k++)
        {
            graph[edges[k][0]][edges[k][1]] = edges[k][2];
            graph[edges[k][1]][edges[k][0]] = edges[k][2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=k && k!=j && i!=j && graph[i][k]!=-1 && graph[k][j]!=-1)
                    {
                        // if(graph[i][j]==-1)
                        // {
                        //     graph[i][j] = graph[i][k] + graph[k][j];
                        // }
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
                
            }
        }
        
        int minCount = 101;
        int city = -1;
        
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(graph[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if(minCount >= count)
            {
                minCount = count;
                city = i;
            }
        }
        
        return city;
    }
};