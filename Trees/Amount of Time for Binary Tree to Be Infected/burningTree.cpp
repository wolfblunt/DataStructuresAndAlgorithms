// Burning Tree

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void createGraph(Node* root, unordered_map<int, vector<int>> &graph)
    {
        if(!root)
        {
            return;
        }
        if(root->left)
        {
            graph[root->data].push_back(root->left->data);
            graph[root->left->data].push_back(root->data);
        }
        if(root->right)
        {
            graph[root->data].push_back(root->right->data);
            graph[root->right->data].push_back(root->data);
        }
        
        createGraph(root->left, graph);
        createGraph(root->right, graph);
    }
    
    
    
    int minTime(Node* root, int target) 
    {
        unordered_map<int, vector<int>> graph;
        createGraph(root, graph);
        
        queue<int> q;
        q.push(target);
        unordered_map<int, bool> visited;
        visited[target] = true;
        int timeToBurn = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto node = q.front();
                q.pop();
                
                for(auto nbrs: graph[node])
                {
                    if(!visited[nbrs])
                    {
                        q.push(nbrs);
                        visited[nbrs] = true;
                    }
                }
            }
            timeToBurn++;
        }
        
        return timeToBurn-1;
    }
};