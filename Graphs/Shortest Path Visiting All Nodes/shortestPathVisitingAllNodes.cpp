// Shortest Path Visiting All Nodes

/*

Approach
Firstly we have our number of nodes stored in n.
The mask represents all the nodes visited.
The visited array tells us if we've visited [i] mask and [j] node.

Now calculate the mask for each node and push it into the queue q.
Also mark the node and its mask visited.
The mask of that node is stored in origMask.

While our q is not empty do the following -

	pop the front of queue into curr.
	currNode is the node in the curr
	currMask if the mask of currNode
	currLength is the length of the path
	if currMask == mask which means all the nodes have been visited, return currLength - 1.
	Else iterate over the adjacency list of the currNode provided and find its neighbors.
	For each neighbor find the newMask and if the neighbor with newMask is not already visited push the neighbor, newMask and currLength + 1 into the queue q. This means that we can go to this newNode.
	Mark the newMask and neighbor visited.
At last if no such path is found, return -1.

*/


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1<<n) - 1;
        queue<pair<int, pair<int,int>>> q; // {node, {nodeMask, currentLengthOfVsistedNodes}}
        vector<vector<bool>> visited(mask+1, vector<bool>(n, false));
        
        for(int i=0;i<n;i++)
        {
            int nodeMask = 1<<i;
            q.push({i, {nodeMask, 1}});
            visited[nodeMask][i] = true;
        }

        while(!q.empty())
        {
            int currNode = q.front().first;
            int currMask = q.front().second.first;
            int currLength = q.front().second.second;
            q.pop();

            if(currMask == mask)
            {
                return currLength-1;
            }

            for(auto a: graph[currNode])
            {
                int neighbor = a;
                int newMask = currMask | (1 << neighbor);

                if(visited[newMask][neighbor])
                {
                    continue;
                }

                q.push({neighbor, {newMask, currLength+1}});
                visited[newMask][neighbor] = true;
            }
        }

        return -1;
    }
};