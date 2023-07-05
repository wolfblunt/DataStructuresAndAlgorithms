// Sum of Left Leaf Nodes

/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf nodes
int leftLeavesSum(Node *root)
{
    queue<pair<Node*, bool>> q;
    q.push({root, false});
    int leftLeafSum = 0;
    while(!q.empty())
    {
        Node* curr = q.front().first;
        bool isLeftLeaf = q.front().second;
        q.pop();

        if(!curr->left && !curr->right && isLeftLeaf)
        {
            leftLeafSum += curr->data;
        }

        if(curr->left)
        {
            q.push({curr->left, true});
        }

        if(curr->right)
        {
            q.push({curr->right, false});
        }
    }
    return leftLeafSum;
}