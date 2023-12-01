// Check whether BST contains Dead End

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool isDeadEnd(Node *root)
    {
        queue<Node*> q;
        set<int> visNodes, leafNodes;
        q.push(root);
        
        while(!q.empty())
        {
            auto *curr = q.front();
            q.pop();
            visNodes.insert(curr->data);
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            if(!curr->left && !curr->right)
            {
                leafNodes.insert(curr->data);
            }
            
            for(auto leaf: leafNodes)
            {
                if((leaf == 1 && visNodes.find(2) != visNodes.end()) || (visNodes.find(leaf-1) != visNodes.end() && visNodes.find(leaf+1) != visNodes.end()))
                {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};