// Min distance between two given nodes of a Binary Tree

struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    Node* findLCA(Node* root, int a, int b)
    {
        if(root==NULL || root->data == a || root->data == b)
        {
            return root;
        }
        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);
        if(left == NULL)
        {
            return right;
        }
        if(right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    
    int distFromLCA(Node* root, int a, int dist)
    {
        if(!root)
        {
            return 0;
        }
        
        if(root->data == a)
        {
            return dist;
        }
        
        int leftDist = distFromLCA(root->left, a, dist+1);
        int rightDist = distFromLCA(root->right, a, dist+1);
        
        if(leftDist > 0)
        {
            return leftDist;
        }
        
        return rightDist;
    }
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lca = findLCA(root, a, b);
        int leftDist = distFromLCA(lca, a, 0);
        int rightDist = distFromLCA(lca, b, 0);
        return leftDist+rightDist;
    }
};