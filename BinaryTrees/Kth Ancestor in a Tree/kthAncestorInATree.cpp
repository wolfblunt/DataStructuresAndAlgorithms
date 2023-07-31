// Kth Ancestor in a Tree

/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/

int kthAncestor(Node *root, int k, int node)
{
    if(!root)
    {
        return -1;
    }
    unordered_map<int, int> parent; // <nodeValue, parent>
    queue<Node*> q;
    parent[root->data] = 0;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if(curr->left)
        {
            parent[curr->left->data] = curr->data;
            q.push(curr->left);
        }
        if(curr->right)
        {
            parent[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }
    
    while(k)
    {
        node = parent[node];
        k--;
    }
    if(node == 0)
    {
        return -1;
    }
    
    return node;
}