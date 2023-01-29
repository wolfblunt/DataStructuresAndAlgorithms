#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f


void addEdge(vector<pair<int,int>> graph[], int source, int destination, int weight)
{
	graph[source].push_back(make_pair(destination, weight));
	graph[destination].push_back(make_pair(source, weight));
}

void shortestPath(vector<pair<int, int>> graph[], int V, int source)
{
	vector<int> dest(V, INF);
	dest[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, source));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for(auto a: graph[u])
		{
			int v = a.first;
			int weight = a.second;

			if(dest[v] > dest[u] + weight)
			{
				dest[v] = dest[u] + weight;
				pq.push(make_pair(dest[v], v));
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		cout<<i<<": "<<dest[i]<<endl;
	}
}

int main()
{
	int V = 9;
	vector<pair<int, int>> graph[V]; 
	addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    shortestPath(graph, V, 0);
}