// Floor in BST

class Solution{

public:
    int floor(Node* root, int x) {
        if(!root)
        {
            return -1;
        }
        if(root->data == x)
        {
            return x;
        }
        else if(root->data > x)
        {
            return floor(root->left, x);
        }
        else
        {
            return max(root->data, floor(root->right, x));
        }
    }
};