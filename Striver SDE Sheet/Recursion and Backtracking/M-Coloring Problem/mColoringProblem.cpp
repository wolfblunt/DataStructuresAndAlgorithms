// M-Coloring Problem

#include <bits/stdc++.h> 

bool canColor(int col, int node, vector<vector<int>> &graph, vector<int> &color, int m, int n)
{
    for(int k=0;k<n;k++)
    {
        if(k!=node && graph[k][node] == 1 && color[k]==col)
        {
            return false;
        }
    }
    return true;
}
    
bool helperFunc(int node, vector<vector<int>> &graph, vector<int> &color, int m, int n)
{
    if(node == n)
        return true;
        
    for(int i=1;i<=m;i++)
    {
        if(canColor(i, node, graph, color, m, n))
        {
            color[node] = i;
            
            if(helperFunc(node+1, graph, color, m, n))
                return true;
                
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0);
    if(helperFunc(0, graph, color, m, n))
        return "YES";
    
    return "NO";
}