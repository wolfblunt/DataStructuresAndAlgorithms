// Leftmost and rightmost nodes of binary tree

void printCorner(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(i==0 || i==n-1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}