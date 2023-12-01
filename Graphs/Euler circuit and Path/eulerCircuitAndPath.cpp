// Euler circuit and Path

class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    int even = 0;
	    int odd = 0;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(adj[i].size() % 2 == 0)
	        {
	            even++;
	        }
	        else
	        {
	            odd++;
	        }
	    }
	    
	    // Eulerian circuit must have all nodes with even degree
	    // Eulerian path must have only 2 nodes with odd degree
	    // Otherwise not a Eulerian circuit and path
	    if(even == V)
	    {
	        return 2;
	    }
	    
	    if(odd == 2)
	    {
	        return 1;
	    }
	    
	    return 0;
	}
};